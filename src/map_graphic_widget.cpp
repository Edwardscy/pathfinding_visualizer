//
// Created by ed on 6/19/22.
//

#include "map_graphic_widget.h"



MapGraphicWidget::MapGraphicWidget(QWidget *parent)
    : QWidget(parent),
      ui_(new Ui_main_widget)

{

    initData();
    initUI();
    initConnect();

}

MapGraphicWidget::~MapGraphicWidget() {

}

void MapGraphicWidget::initData() {

}

void MapGraphicWidget::initUI() {

    ui_->setupUi(this);

    scene_ = new QGraphicsScene(this);
    scene_->setSceneRect(0, 0, 500, 500);


    ui_->graphic_view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui_->graphic_view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui_->graphic_view->setScene(scene_);


    // setting default grid size (50px)
    int grid_size = 50;

    grid_map_ = new GridMap(grid_size, scene_);
    grid_map_->renderGrids(grid_size);

}

void MapGraphicWidget::initConnect() {


}

