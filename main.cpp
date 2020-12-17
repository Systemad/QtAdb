#include "adbapp.h"
#include <flattabwidget.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AdbApp w;
    w.show();
    return a.exec();
}
