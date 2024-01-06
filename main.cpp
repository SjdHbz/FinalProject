#include "project.h"
#include "land.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    land w;
    w.show();
    return a.exec();
}
