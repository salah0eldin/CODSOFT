#include "ImageEdit.h"

#include <opencv2/opencv.hpp>

#include <QGraphicsBlurEffect>
#include <QGraphicsRectItem>
#include <QDragEnterEvent>
#include <qstylefactory.h>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QImageReader>
#include <QMessageBox>
#include <QFileDialog>
#include <qpalette.h>
#include <QMimeData>
#include <iostream>
#include <QPainter>
#include <QPixmap>
#include <QVector>
#include <QImage>
#include <QDebug>

//==============================================================================================//


ImageEdit::ImageEdit(QWidget* parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow())
{
	//set the visibility to the elements at startup
	ui->setupUi(this);
	ui->ToolsBox->setVisible(false);
	ui->ToolsLine->setVisible(false);
	ui->FiltersBox->setVisible(false);
	ui->ColorsBox->setVisible(false);
	ui->CropBox->setVisible(false);
	ui->ResizeBox->setVisible(false);
	ui->cropFrame->setVisible(false);
	ui->cropFrame->setGeometry(0, 0, 0, 0);

	//dark mode part
	qApp->setStyle(QStyleFactory::create("Fusion"));

	QPalette darkPalette;
	darkPalette.setColor(QPalette::Window, QColor(53, 53, 53));
	darkPalette.setColor(QPalette::WindowText, Qt::white);
	darkPalette.setColor(QPalette::Base, QColor(25, 25, 25));
	darkPalette.setColor(QPalette::AlternateBase, QColor(53, 53, 53));
	darkPalette.setColor(QPalette::ToolTipBase, Qt::white);
	darkPalette.setColor(QPalette::ToolTipText, Qt::white);
	darkPalette.setColor(QPalette::Text, Qt::white);
	darkPalette.setColor(QPalette::Button, QColor(53, 53, 53));
	darkPalette.setColor(QPalette::ButtonText, Qt::white);
	darkPalette.setColor(QPalette::BrightText, Qt::red);
	darkPalette.setColor(QPalette::Link, QColor(42, 130, 218));

	darkPalette.setColor(QPalette::Highlight, QColor(42, 130, 218));
	darkPalette.setColor(QPalette::HighlightedText, Qt::black);

	qApp->setPalette(darkPalette);

	qApp->setStyleSheet("QToolTip { color: #ffffff; background-color: #2a82da; border: 1px solid white; }");
}

ImageEdit::~ImageEdit()
{
	delete ui;
}

//==============================================================================================//

//function to add all the filters and edits on the image
void ImageEdit::updateImage() {
	if (CropedResized.isNull()) {
		return;
	}

	int kernelSize = 5;
	QImage resizedImage = CropedResized.scaled(QSize(100 * kernelSize, 100 * kernelSize), Qt::KeepAspectRatio, Qt::SmoothTransformation);

	cv::Mat cvEdited(resizedImage.height(), resizedImage.width(), CV_8UC4, const_cast<uchar*>(resizedImage.bits()), resizedImage.bytesPerLine());

	// for grayscale
	if (grayVal) {
		cv::Mat grayImage;
		cv::cvtColor(cvEdited, grayImage, cv::COLOR_RGBA2GRAY);
		cv::cvtColor(grayImage, cvEdited, cv::COLOR_GRAY2BGRA);
	}
	// for blur effect
	if (blurVal > 0) {
		cv::GaussianBlur(cvEdited, cvEdited, cv::Size(kernelSize, kernelSize), blurVal);
	}
	//for sharpen effect
	if (sharpVal > 0) {
		cv::Mat sharpnessKernel = (cv::Mat_<float>(3, 3) <<
			-1, -1, -1,
			-1, 9 + sharpVal, -1,
			-1, -1, -1);

		cv::filter2D(cvEdited, cvEdited, -1, sharpnessKernel);

	}
	// for saturation filter
	if (satVal != 0) {
		cv::Mat lut(1, 256, CV_8U);

		double colorFactor = static_cast<double>(satVal) / 100.0;

		for (int i = 0; i < 256; i++) {
			int adjustedValue = cv::saturate_cast<uchar>(i + colorFactor * 255);
			lut.at<uchar>(i) = static_cast<uchar>(adjustedValue);
		}

		cv::LUT(cvEdited, lut, cvEdited);
	}
	//for brightness control
	if (brightVal != 0) {
		double alpha = 1.0 + (brightVal) / 100.0;
		cvEdited *= alpha;
	}
	//for contrast control
	if (contVal != 0) {
		double contrastFactor = (100.0 + contVal) / 100.0;
		cvEdited.convertTo(cvEdited, -1, contrastFactor, 0);
	}

	edited = QImage(cvEdited.data, cvEdited.cols, cvEdited.rows, cvEdited.step, QImage::Format_ARGB32);

	edited = edited.scaled(CropedResized.size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
	//show the image
	QPixmap pix = QPixmap::fromImage(edited);
	ui->ImageLable->setPixmap(pix.scaled(ui->ImageLable->width(), ui->ImageLable->height(), Qt::KeepAspectRatio));
}

//==============================================================================================//

//function called when selecting a new image to reset every thing
void ImageEdit::onNewImage() {
	ui->DownloadButton->setEnabled(true);
	ui->EditButton->setEnabled(true);

	blurVal = 0;
	grayVal = 0;
	sharpVal = 0;
	satVal = 0;
	brightVal = 0;
	contVal = 0;

	ui->BlurDial->setValue(0);
	ui->SharpenDial->setValue(0);
	ui->GrayCheckBox->setChecked(0);
	ui->satDial->setValue(0);
	ui->brightDial->setValue(0);
	ui->contDial->setValue(0);

	ui->FiltersBox->setVisible(false);
	ui->ColorsBox->setVisible(false);
	ui->ResizeBox->setVisible(false);
	ui->CropBox->setVisible(false);
}

//handel the select button
void ImageEdit::on_SelectButton_clicked()
{
	QString filename = QFileDialog::getOpenFileName(this, tr("Select Image"), QDir::homePath(), tr("Images (*.png *.jpg)"));
	if (!filename.isEmpty()) {
		original = CropedResized = edited = QImage(filename);
		QPixmap pix = QPixmap::fromImage(original);

		ui->ImageLable->setPixmap(pix.scaled(ui->ImageLable->width(), ui->ImageLable->height(), Qt::KeepAspectRatio));

		onNewImage();
	}
}

//handel the download button
void ImageEdit::on_DownloadButton_clicked()
{
	QString fileName = QFileDialog::getSaveFileName(this, "Save Image", QString(), "Images (*.png *.jpg)");
	if (!fileName.isEmpty()) {
		if (edited.save(fileName)) {
			QMessageBox::information(this, "Saved", "Image saved successfully.");
		}
		else {
			QMessageBox::warning(this, "Error", "Failed to save the image.");
		}
	}
}

//handel the edit button
void ImageEdit::on_EditButton_clicked()
{
	ui->ToolsBox->setVisible(!ui->ToolsBox->isVisible());
	ui->ToolsLine->setVisible(ui->ToolsBox->isVisible());
	ui->FiltersBox->setVisible(false);
}

//handel the filters button
void ImageEdit::on_FiltersButton_clicked()
{
	ui->ColorsBox->setVisible(false);
	ui->CropBox->setVisible(false);
	ui->ResizeBox->setVisible(false);
	ui->FiltersBox->setVisible(!ui->FiltersBox->isVisible());
}

//handel the corlors button
void ImageEdit::on_ColorsButton_clicked()
{
	ui->FiltersBox->setVisible(false);
	ui->CropBox->setVisible(false);
	ui->ResizeBox->setVisible(false);
	ui->ColorsBox->setVisible(!ui->ColorsBox->isVisible());
}

//handel the crop button
void ImageEdit::on_CropButton_clicked()
{
	ui->FiltersBox->setVisible(false);
	ui->ColorsBox->setVisible(false);
	ui->ResizeBox->setVisible(false);
	ui->CropBox->setVisible(true);

	QPixmap pix = QPixmap::fromImage(original);
	ui->ImageLable->setPixmap(pix.scaled(ui->ImageLable->width(), ui->ImageLable->height(), Qt::KeepAspectRatio));
	isCropping = 1;
	ui->cropFrame->setVisible(true);

	ui->SelectButton->setEnabled(false);
	ui->DownloadButton->setEnabled(false);
	ui->EditButton->setEnabled(false);
	ui->FiltersButton->setEnabled(false);
	ui->ColorsButton->setEnabled(false);
	ui->CropButton->setEnabled(false);
	ui->ResizeButton->setEnabled(false);
}

//handel the resize button
void ImageEdit::on_ResizeButton_clicked()
{
	ui->FiltersBox->setVisible(false);
	ui->CropBox->setVisible(false);
	ui->ColorsBox->setVisible(false);
	ui->ResizeBox->setVisible(!ui->ResizeBox->isVisible());
	isCropping = 0;
	ui->cropFrame->setVisible(false);

	ui->imageHL->setText("Original Height : " + QString::number(original.height()) + " px");
	ui->imageWL->setText("Original Width : " + QString::number(original.width()) + " px");

	ui->imageHL_2->setText("current : " + QString::number(CropedResized.height()) + " px");
	ui->imageWL_2->setText("current : " + QString::number(CropedResized.width()) + " px");
}

//handel the blur dial
void ImageEdit::on_BlurDial_valueChanged(int value)
{
	blurVal = value / 20.0;
	ui->blurLabel->setText(QString::number(value) + "%");
	updateImage();
}

//handel the sharpen dial
void ImageEdit::on_SharpenDial_valueChanged(int value)
{
	sharpVal = 4 * value / 1000.0;
	ui->sharpenLabel->setText(QString::number(value) + "%");
	updateImage();
}

//handel the grayscale checkbox
void ImageEdit::on_GrayCheckBox_stateChanged(int arg1)
{
	grayVal = arg1;
	updateImage();
}

//handel the saturation dial
void ImageEdit::on_satDial_valueChanged(int value) {
	satVal = value;
	ui->satLabel->setText(QString::number(value) + "%");
	updateImage();
}

//handle the brightness dial
void ImageEdit::on_brightDial_valueChanged(int value) {
	brightVal = value;
	ui->brightLabel->setText(QString::number(value) + "%");
	updateImage();
}

//handel the contrast dial
void ImageEdit::on_contDial_valueChanged(int value) {
	contVal = value;
	ui->contLabel->setText(QString::number(value) + "%");
	updateImage();
}

//handel the resize button to resize the image
void ImageEdit::on_resizeResizeButton_clicked() {
	CropedResized = CropedResized.scaled(ui->wdithQL->text().toInt(), ui->HeightQL->text().toInt());
	updateImage();

	ui->imageHL_2->setText("current : " + QString::number(CropedResized.height()) + " px");
	ui->imageWL_2->setText("current : " + QString::number(CropedResized.width()) + " px");
}

//handel the crop button the crop the image
void ImageEdit::on_cropCropButton_clicked() {
	QRect rect;
	float xratio = original.width() / (float)ui->ImageLable->pixmap().width();
	float yratio = original.height() / (float)ui->ImageLable->pixmap().height();
	float xp = (ui->ImageLable->width() - ui->ImageLable->pixmap().width()) / 2 + 10;
	float yp = (ui->ImageLable->height() - ui->ImageLable->pixmap().height()) / 2 + 10;

	rect.setX(xratio * (ui->cropFrame->x() - xp));
	rect.setY(yratio * (ui->cropFrame->y() - yp));
	rect.setWidth(xratio * ui->cropFrame->width());
	rect.setHeight(yratio * ui->cropFrame->height());
	/*qDebug() << original.width() << " " << original.height();
	qDebug() << ui->ImageLable->pixmap().width() << " " << ui->ImageLable->pixmap().height();
	qDebug() << xratio << " " << yratio << " " << xp << " " << yp;
	qDebug() << rect;*/

	CropedResized = original.copy(rect);
	ui->CropBox->setVisible(false);
	ui->cropFrame->setVisible(false);
	isCropping = 0;
	ui->cropCropButton->setEnabled(false);
	updateImage();

	ui->SelectButton->setEnabled(true);
	ui->DownloadButton->setEnabled(true);
	ui->EditButton->setEnabled(true);
	ui->FiltersButton->setEnabled(true);
	ui->ColorsButton->setEnabled(true);
	ui->CropButton->setEnabled(true);
	ui->ResizeButton->setEnabled(true);
}

//handle the cancel crop button the cancel the croping process
void ImageEdit::on_cancelCropButton_clicked() {
	QPixmap pix = QPixmap::fromImage(edited);
	ui->ImageLable->setPixmap(pix.scaled(ui->ImageLable->width(), ui->ImageLable->height(), Qt::KeepAspectRatio));
	isCropping = 0;
	ui->cropFrame->setVisible(false);
	ui->CropBox->setVisible(false);

	ui->SelectButton->setEnabled(true);
	ui->DownloadButton->setEnabled(true);
	ui->EditButton->setEnabled(true);
	ui->FiltersButton->setEnabled(true);
	ui->ColorsButton->setEnabled(true);
	ui->CropButton->setEnabled(true);
	ui->ResizeButton->setEnabled(true);
}

//handelt he mouse event when cropping
void ImageEdit::mousePressEvent(QMouseEvent* event) {
	if (isCropping) {
		if (event->button() == Qt::LeftButton) {
			lastMousePos = event->pos();
			isMoving = true;
			ui->cropFrame->setFixedSize(0, 0);
			ui->cropFrame->setGeometry(event->pos().x(), event->pos().y(), 0, 0);
		}
	}
}

//handel the mouse moving when croping
void ImageEdit::mouseMoveEvent(QMouseEvent* event) {
	if (isMoving) {
		ui->cropFrame->setFixedSize(event->pos().x() - lastMousePos.x(), event->pos().y() - lastMousePos.y());
	}
}

//handel the release mouse when croping
void ImageEdit::mouseReleaseEvent(QMouseEvent* event) {
	if (event->button() == Qt::LeftButton) {
		isMoving = false;
		ui->cropCropButton->setEnabled(true);
	}
}

//handel the drag event
void ImageEdit::dragEnterEvent(QDragEnterEvent* event) {
	if (event->mimeData()->hasUrls() && event->mimeData()->urls().count() == 1) {
		QString filePath = event->mimeData()->urls().first().toLocalFile();
		if (QImageReader::imageFormat(filePath).isEmpty()) {
			event->ignore();
		}
		else {
			event->acceptProposedAction();
		}
	}
	else {
		event->ignore();
	}
}

//handel the drop event to select new image
void ImageEdit::dropEvent(QDropEvent* event) {
	QString imagePath = event->mimeData()->urls().first().toLocalFile();

	QImage image(imagePath);
	if (!image.isNull()) {
		original = CropedResized = edited = image;
		QPixmap pix = QPixmap::fromImage(image);
		ui->ImageLable->setPixmap(pix.scaled(ui->ImageLable->width(), ui->ImageLable->height(), Qt::KeepAspectRatio));
		onNewImage();
		event->acceptProposedAction();
	}
	else {
		event->ignore();
	}
}


