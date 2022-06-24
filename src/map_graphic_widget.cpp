//
// Created by ed on 6/19/22.
//

#include "map_graphic_widget.h"

#include "parse_data.h"

#include <QDebug>


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

    connect(ui_->load_map_bt, SIGNAL(clicked()), this,
            SLOT(slot_load_map_bt()));

    connect(ui_->load_cbs_result_bt, SIGNAL(clicked()), this,
            SLOT(slot_load_cbs_result_bt()));
}


void MapGraphicWidget::slot_load_map_bt()
{

    QString filter;
    filter = "";

    file_name
            = QFileDialog::getOpenFileName(this, tr("Open file"), m_directory, filter);
    if (file_name.isEmpty())
        return;

    QFileInfo info(file_name);
    m_directory = info.absoluteDir().absolutePath();

    file.setFileName(file_name);

    if (!file.open(QFile::ReadOnly)) {
        QString msg = tr("Failed to open %1\n%2")
                .arg(QDir::toNativeSeparators(file_name), file.errorString());
        QMessageBox::warning(this, tr("Error"), msg);
        return;
    }

    QString load_file_name = info.fileName();
    QString load_file_path_name = info.path();
    QStringList load_file_name_list = load_file_name.split(".");

    qDebug() << "load_file_name:" << load_file_name;
    qDebug() << "load_file_path_name:" << load_file_path_name;
    qDebug() << "file_name: " << file_name;

    /////
    QTextStream in(&file);

    ParseMapData parse_map_obj;
    parse_map_obj.parse(in);

//    parse_map_data(in);

//    QString line = in.readLine();



////    qDebug() << line;
//    while  (!line.isNull())
//    {
////         process_line(line);
//        line = in.readLine();
////        displayString.append(line);
//        qDebug() << line;
//    }
////    ui->textEdit->clear();
////    ui->textEdit->setPlainText(displayString);


}

void MapGraphicWidget::slot_load_cbs_result_bt()
{

    qDebug() << "slot_load_cbs_result_bt" ;
}


void MapGraphicWidget::parse_map_file()
{

}

void MapGraphicWidget::parse_cbs_result_file()
{

}


