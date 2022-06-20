//
// Created by ed on 6/19/22.
//

#ifndef PATHFINDING_VISUALIZER_MAP_GRAPHIC_WIDGET_H
#define PATHFINDING_VISUALIZER_MAP_GRAPHIC_WIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsDropShadowEffect>
#include <QVBoxLayout>
#include <QPushButton>

#include "main_widget.h"
#include "grip_map.h"

class MapGraphicWidget: public QWidget
{
    Q_OBJECT

public:
    explicit MapGraphicWidget(QWidget* parent = Q_NULLPTR);
    ~MapGraphicWidget();

public:
    void initData();
    void initUI();
    void initConnect();

private:
    Ui_main_widget* ui_;


    QGraphicsScene *scene_;

    GridMap *grid_map_;


};




#endif //PATHFINDING_VISUALIZER_MAP_GRAPHIC_WIDGET_H
