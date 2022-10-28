#include "CustomCollectionWidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CustomCollectionWidget w;
    w.show();
    return a.exec();
}
