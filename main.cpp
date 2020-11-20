#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

      system("echo 41 > /sys/class/gpio/export");
      system("echo out > /sys/class/gpio/gpio41/direction");
int a;
    w.show();
    return a.exec();
}
