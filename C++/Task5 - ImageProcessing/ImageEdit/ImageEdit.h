#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ImageEdit.h"

class ImageEdit : public QMainWindow
{
	Q_OBJECT

public:
	ImageEdit(QWidget* parent = nullptr);
	~ImageEdit();
	void updateImage();
	void onNewImage();

private slots:
	void on_SelectButton_clicked();

	void on_EditButton_clicked();

	void on_DownloadButton_clicked();

	void on_FiltersButton_clicked();

	void on_ColorsButton_clicked();

	void on_CropButton_clicked();

	void on_ResizeButton_clicked();

	void on_BlurDial_valueChanged(int value);

	void on_SharpenDial_valueChanged(int value);

	void on_GrayCheckBox_stateChanged(int arg1);

	void on_satDial_valueChanged(int value);

	void on_brightDial_valueChanged(int value);

	void on_contDial_valueChanged(int value);

	void on_resizeResizeButton_clicked();

	void on_cropCropButton_clicked();

	void on_cancelCropButton_clicked();


protected:
	void dragEnterEvent(QDragEnterEvent* event) override;

	void dropEvent(QDropEvent* event) override;

	void mousePressEvent(QMouseEvent* event) override;

	void mouseMoveEvent(QMouseEvent* event) override;

	void mouseReleaseEvent(QMouseEvent* event) override;

private:
	Ui::MainWindow* ui;

	QPoint lastMousePos;
	bool isCropping = 0, isMoving = 0;
	QImage original, CropedResized, edited;
	float blurVal = 0;
	bool grayVal = 0;
	float sharpVal = 0;
	float satVal = 0;
	float brightVal = 0;
	float contVal = 0;
};
