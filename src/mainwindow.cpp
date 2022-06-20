//
// Created by ed on 6/19/22.
//

#include "mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    initData();
    initUI();
    initConnect();
}

MainWindow::~MainWindow() {

}

void MainWindow::initData() {



}

void MainWindow::initUI() {

    m_map_graphic_widget = new MapGraphicWidget();

    setCentralWidget(m_map_graphic_widget);
}

void MainWindow::initConnect() {


}

