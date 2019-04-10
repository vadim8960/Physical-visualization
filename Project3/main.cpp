#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);    // Считывание параметров командной строки
    MainWindow w;                  // Инициализация оконного приложения
    w.show();                      // Запуск оконного приложения

    return a.exec();
}
