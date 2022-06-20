//
// Created by ed on 6/19/22.
//

#ifndef PATHFINDING_VISUALIZER_MAINWINDOW_H
#define PATHFINDING_VISUALIZER_MAINWINDOW_H


#include <QMainWindow>
#include <QWidget>


#include "map_graphic_widget.h"


class MainWindow: public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = Q_NULLPTR);

    ~MainWindow();

public:
    void initData();
    void initUI();
    void initConnect();

private:

    MapGraphicWidget* m_map_graphic_widget;



};



#endif //PATHFINDING_VISUALIZER_MAINWINDOW_H
