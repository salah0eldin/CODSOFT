#include "ImageEdit.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ImageEdit w;
    w.show();
    return a.exec();
}
