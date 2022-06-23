//
// Created by ed on 6/19/22.
//

#ifndef PATHFINDING_VISUALIZER_MAP_GRAPHIC_WIDGET_H
#define PATHFINDING_VISUALIZER_MAP_GRAPHIC_WIDGET_H

#include <QObject>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>

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

public:
    void parse_map_file();
    void parse_cbs_result_file();

public slots:
    void slot_load_map_bt();
    void slot_load_cbs_result_bt();

private:
    Ui_main_widget* ui_;

    QGraphicsScene *scene_;

    GridMap *grid_map_;

private:
    QFile file;
    QString file_name;
    QString m_directory;


};




#endif //PATHFINDING_VISUALIZER_MAP_GRAPHIC_WIDGET_H
