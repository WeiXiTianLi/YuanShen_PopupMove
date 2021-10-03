#include "YuanShen_PopupMove.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    YuanShen_PopupMove w;
    w.show();
    return a.exec();
}
