

#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    QApplication::setApplicationName("pathfinding visualizer 1.00");

    MainWindow w;
    w.setMinimumSize(1200,800);
    w.show();
    return a.exec();

}

