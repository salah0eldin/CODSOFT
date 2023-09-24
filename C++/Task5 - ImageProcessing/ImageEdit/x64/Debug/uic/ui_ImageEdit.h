/********************************************************************************
** Form generated from reading UI file 'ImageEdit.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGEEDIT_H
#define UI_IMAGEEDIT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDial>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *line;
    QFrame *line_2;
    QFrame *ToolsLine;
    QGroupBox *ToolsBox;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *FiltersButton;
    QPushButton *ColorsButton;
    QPushButton *CropButton;
    QPushButton *ResizeButton;
    QGroupBox *groupBox_2;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *SelectButton;
    QPushButton *DownloadButton;
    QPushButton *EditButton;
    QLabel *ImageLable;
    QGroupBox *FiltersBox;
    QDial *BlurDial;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QDial *SharpenDial;
    QFrame *line_3;
    QFrame *line_5;
    QLabel *blurLabel;
    QLabel *sharpenLabel;
    QCheckBox *GrayCheckBox;
    QGroupBox *ColorsBox;
    QDial *satDial;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QDial *brightDial;
    QFrame *line_4;
    QFrame *line_6;
    QLabel *satLabel;
    QLabel *brightLabel;
    QLabel *contLabel;
    QDial *contDial;
    QGroupBox *CropBox;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *cropCropButton;
    QPushButton *cancelCropButton;
    QGroupBox *ResizeBox;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *resizeResizeButton;
    QLineEdit *HeightQL;
    QLineEdit *wdithQL;
    QLabel *imageHL;
    QLabel *imageWL;
    QLabel *widthL;
    QLabel *heightL;
    QLabel *imageHL_2;
    QLabel *imageWL_2;
    QFrame *cropFrame;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(730, 490);
        QFont font;
        font.setBold(false);
        font.setKerning(true);
        MainWindow->setFont(font);
        MainWindow->setAcceptDrops(true);
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("applications-graphics")));
        MainWindow->setWindowIcon(icon);
        MainWindow->setWindowOpacity(1.000000000000000);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        line = new QFrame(centralwidget);
        line->setObjectName("line");
        line->setGeometry(QRect(523, 10, 20, 361));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(centralwidget);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(10, 370, 711, 20));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        ToolsLine = new QFrame(centralwidget);
        ToolsLine->setObjectName("ToolsLine");
        ToolsLine->setGeometry(QRect(540, 150, 181, 20));
        ToolsLine->setFrameShape(QFrame::HLine);
        ToolsLine->setFrameShadow(QFrame::Sunken);
        ToolsBox = new QGroupBox(centralwidget);
        ToolsBox->setObjectName("ToolsBox");
        ToolsBox->setGeometry(QRect(540, 170, 181, 181));
        verticalLayoutWidget_2 = new QWidget(ToolsBox);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(10, 20, 171, 151));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        FiltersButton = new QPushButton(verticalLayoutWidget_2);
        FiltersButton->setObjectName("FiltersButton");

        verticalLayout_2->addWidget(FiltersButton);

        ColorsButton = new QPushButton(verticalLayoutWidget_2);
        ColorsButton->setObjectName("ColorsButton");

        verticalLayout_2->addWidget(ColorsButton);

        CropButton = new QPushButton(verticalLayoutWidget_2);
        CropButton->setObjectName("CropButton");

        verticalLayout_2->addWidget(CropButton);

        ResizeButton = new QPushButton(verticalLayoutWidget_2);
        ResizeButton->setObjectName("ResizeButton");

        verticalLayout_2->addWidget(ResizeButton);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(540, 10, 181, 131));
        verticalLayoutWidget = new QWidget(groupBox_2);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(10, 20, 171, 104));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        SelectButton = new QPushButton(verticalLayoutWidget);
        SelectButton->setObjectName("SelectButton");

        verticalLayout->addWidget(SelectButton);

        DownloadButton = new QPushButton(verticalLayoutWidget);
        DownloadButton->setObjectName("DownloadButton");
        DownloadButton->setEnabled(false);

        verticalLayout->addWidget(DownloadButton);

        EditButton = new QPushButton(verticalLayoutWidget);
        EditButton->setObjectName("EditButton");
        EditButton->setEnabled(false);

        verticalLayout->addWidget(EditButton);

        ImageLable = new QLabel(centralwidget);
        ImageLable->setObjectName("ImageLable");
        ImageLable->setGeometry(QRect(10, 10, 511, 361));
        ImageLable->setAcceptDrops(true);
        ImageLable->setFrameShape(QFrame::Box);
        ImageLable->setFrameShadow(QFrame::Sunken);
        ImageLable->setLineWidth(1);
        ImageLable->setMidLineWidth(0);
        ImageLable->setAlignment(Qt::AlignCenter);
        ImageLable->setWordWrap(true);
        ImageLable->setMargin(0);
        FiltersBox = new QGroupBox(centralwidget);
        FiltersBox->setObjectName("FiltersBox");
        FiltersBox->setGeometry(QRect(10, 380, 711, 81));
        FiltersBox->setFlat(false);
        BlurDial = new QDial(FiltersBox);
        BlurDial->setObjectName("BlurDial");
        BlurDial->setGeometry(QRect(90, 10, 61, 71));
        BlurDial->setMaximum(100);
        label = new QLabel(FiltersBox);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 40, 49, 16));
        label_2 = new QLabel(FiltersBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(350, 40, 61, 16));
        label_3 = new QLabel(FiltersBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(170, 40, 61, 16));
        SharpenDial = new QDial(FiltersBox);
        SharpenDial->setObjectName("SharpenDial");
        SharpenDial->setGeometry(QRect(270, 10, 61, 71));
        SharpenDial->setMinimum(0);
        SharpenDial->setMaximum(100);
        line_3 = new QFrame(FiltersBox);
        line_3->setObjectName("line_3");
        line_3->setGeometry(QRect(150, 30, 20, 41));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_5 = new QFrame(FiltersBox);
        line_5->setObjectName("line_5");
        line_5->setGeometry(QRect(330, 30, 20, 41));
        line_5->setFrameShape(QFrame::VLine);
        line_5->setFrameShadow(QFrame::Sunken);
        blurLabel = new QLabel(FiltersBox);
        blurLabel->setObjectName("blurLabel");
        blurLabel->setGeometry(QRect(60, 40, 49, 16));
        sharpenLabel = new QLabel(FiltersBox);
        sharpenLabel->setObjectName("sharpenLabel");
        sharpenLabel->setGeometry(QRect(230, 40, 49, 16));
        GrayCheckBox = new QCheckBox(FiltersBox);
        GrayCheckBox->setObjectName("GrayCheckBox");
        GrayCheckBox->setGeometry(QRect(420, 40, 76, 20));
        ColorsBox = new QGroupBox(centralwidget);
        ColorsBox->setObjectName("ColorsBox");
        ColorsBox->setGeometry(QRect(10, 380, 711, 81));
        ColorsBox->setFlat(false);
        satDial = new QDial(ColorsBox);
        satDial->setObjectName("satDial");
        satDial->setGeometry(QRect(120, 10, 61, 71));
        satDial->setMinimum(-100);
        satDial->setMaximum(100);
        label_4 = new QLabel(ColorsBox);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(18, 40, 71, 16));
        label_5 = new QLabel(ColorsBox);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(380, 40, 61, 16));
        label_6 = new QLabel(ColorsBox);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(200, 40, 71, 16));
        brightDial = new QDial(ColorsBox);
        brightDial->setObjectName("brightDial");
        brightDial->setGeometry(QRect(300, 10, 61, 71));
        brightDial->setMinimum(-100);
        brightDial->setMaximum(100);
        line_4 = new QFrame(ColorsBox);
        line_4->setObjectName("line_4");
        line_4->setGeometry(QRect(180, 30, 20, 41));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);
        line_6 = new QFrame(ColorsBox);
        line_6->setObjectName("line_6");
        line_6->setGeometry(QRect(360, 30, 20, 41));
        line_6->setFrameShape(QFrame::VLine);
        line_6->setFrameShadow(QFrame::Sunken);
        satLabel = new QLabel(ColorsBox);
        satLabel->setObjectName("satLabel");
        satLabel->setGeometry(QRect(90, 40, 49, 16));
        brightLabel = new QLabel(ColorsBox);
        brightLabel->setObjectName("brightLabel");
        brightLabel->setGeometry(QRect(270, 40, 49, 16));
        contLabel = new QLabel(ColorsBox);
        contLabel->setObjectName("contLabel");
        contLabel->setGeometry(QRect(440, 40, 49, 16));
        contDial = new QDial(ColorsBox);
        contDial->setObjectName("contDial");
        contDial->setGeometry(QRect(480, 10, 61, 71));
        contDial->setMinimum(-100);
        contDial->setMaximum(100);
        CropBox = new QGroupBox(centralwidget);
        CropBox->setObjectName("CropBox");
        CropBox->setGeometry(QRect(10, 380, 711, 81));
        CropBox->setFlat(false);
        horizontalLayoutWidget = new QWidget(CropBox);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(60, 20, 201, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        cropCropButton = new QPushButton(horizontalLayoutWidget);
        cropCropButton->setObjectName("cropCropButton");
        cropCropButton->setEnabled(false);

        horizontalLayout->addWidget(cropCropButton);

        cancelCropButton = new QPushButton(horizontalLayoutWidget);
        cancelCropButton->setObjectName("cancelCropButton");

        horizontalLayout->addWidget(cancelCropButton);

        ResizeBox = new QGroupBox(centralwidget);
        ResizeBox->setObjectName("ResizeBox");
        ResizeBox->setGeometry(QRect(10, 380, 711, 81));
        ResizeBox->setFlat(false);
        horizontalLayoutWidget_2 = new QWidget(ResizeBox);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(510, 20, 161, 41));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        resizeResizeButton = new QPushButton(horizontalLayoutWidget_2);
        resizeResizeButton->setObjectName("resizeResizeButton");

        horizontalLayout_2->addWidget(resizeResizeButton);

        HeightQL = new QLineEdit(ResizeBox);
        HeightQL->setObjectName("HeightQL");
        HeightQL->setGeometry(QRect(400, 22, 61, 20));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(HeightQL->sizePolicy().hasHeightForWidth());
        HeightQL->setSizePolicy(sizePolicy);
        wdithQL = new QLineEdit(ResizeBox);
        wdithQL->setObjectName("wdithQL");
        wdithQL->setGeometry(QRect(400, 50, 61, 21));
        sizePolicy.setHeightForWidth(wdithQL->sizePolicy().hasHeightForWidth());
        wdithQL->setSizePolicy(sizePolicy);
        imageHL = new QLabel(ResizeBox);
        imageHL->setObjectName("imageHL");
        imageHL->setGeometry(QRect(10, 20, 181, 16));
        imageWL = new QLabel(ResizeBox);
        imageWL->setObjectName("imageWL");
        imageWL->setGeometry(QRect(10, 50, 181, 16));
        widthL = new QLabel(ResizeBox);
        widthL->setObjectName("widthL");
        widthL->setGeometry(QRect(340, 50, 49, 16));
        heightL = new QLabel(ResizeBox);
        heightL->setObjectName("heightL");
        heightL->setGeometry(QRect(340, 20, 49, 16));
        imageHL_2 = new QLabel(ResizeBox);
        imageHL_2->setObjectName("imageHL_2");
        imageHL_2->setGeometry(QRect(190, 20, 141, 16));
        imageWL_2 = new QLabel(ResizeBox);
        imageWL_2->setObjectName("imageWL_2");
        imageWL_2->setGeometry(QRect(190, 50, 141, 16));
        cropFrame = new QFrame(centralwidget);
        cropFrame->setObjectName("cropFrame");
        cropFrame->setGeometry(QRect(130, 140, 120, 80));
        cropFrame->setFrameShape(QFrame::Box);
        cropFrame->setFrameShadow(QFrame::Plain);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 730, 22));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Image Editor", nullptr));
        ToolsBox->setTitle(QCoreApplication::translate("MainWindow", "Tools", nullptr));
        FiltersButton->setText(QCoreApplication::translate("MainWindow", "Filters", nullptr));
        ColorsButton->setText(QCoreApplication::translate("MainWindow", "Color Adjustment", nullptr));
        CropButton->setText(QCoreApplication::translate("MainWindow", "Crop", nullptr));
        ResizeButton->setText(QCoreApplication::translate("MainWindow", "Resize", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Controls", nullptr));
        SelectButton->setText(QCoreApplication::translate("MainWindow", "Select Image", nullptr));
        DownloadButton->setText(QCoreApplication::translate("MainWindow", "Download", nullptr));
        EditButton->setText(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        ImageLable->setText(QString());
        FiltersBox->setTitle(QCoreApplication::translate("MainWindow", "Filters", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Blur :", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Gray Scale :", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Sharpen :", nullptr));
        blurLabel->setText(QCoreApplication::translate("MainWindow", "0%", nullptr));
        sharpenLabel->setText(QCoreApplication::translate("MainWindow", "0%", nullptr));
        GrayCheckBox->setText(QString());
        ColorsBox->setTitle(QCoreApplication::translate("MainWindow", "Color Adjustment", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Saturation :", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Contrast", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Brightness :", nullptr));
        satLabel->setText(QCoreApplication::translate("MainWindow", "0%", nullptr));
        brightLabel->setText(QCoreApplication::translate("MainWindow", "0%", nullptr));
        contLabel->setText(QCoreApplication::translate("MainWindow", "0%", nullptr));
        CropBox->setTitle(QCoreApplication::translate("MainWindow", "Crop", nullptr));
        cropCropButton->setText(QCoreApplication::translate("MainWindow", "Crop", nullptr));
        cancelCropButton->setText(QCoreApplication::translate("MainWindow", "Cancel", nullptr));
        ResizeBox->setTitle(QCoreApplication::translate("MainWindow", "Resize", nullptr));
        resizeResizeButton->setText(QCoreApplication::translate("MainWindow", "Resize", nullptr));
        imageHL->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        imageWL->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        widthL->setText(QCoreApplication::translate("MainWindow", "Width :", nullptr));
        heightL->setText(QCoreApplication::translate("MainWindow", "Height :", nullptr));
        imageHL_2->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        imageWL_2->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEEDIT_H
