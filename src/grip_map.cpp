//
// Created by ed on 6/19/22.
//


#include "grip_map.h"

#include <math.h>

#include <QDebug>
#include <algorithm>
#include <iostream>
#include <random>

GridMap::GridMap(int grid_size, QGraphicsScene *scene)
        : QObject(),
          grid_size_{grid_size},
          grids_(new QList<Grid *>()),
          scene_{scene},
          is_start_config_button_checked_{true},
          place_config_mode_{false},
          edit_map_mode_{false}

{

    ellipse_ = new QList<Ellipse *>();

    graphics_text_ = new QList<GraphicsText* >();
    path_ = new QList<Path* >();

    this->step = 0;

}

GridMap::~GridMap() { delete grids_; }

void GridMap::setGridSize(int size) { grid_size_ = size; }

void GridMap::setPlaceConfigMode(bool b) { place_config_mode_ = b; }

void GridMap::setEditingMapMode(bool b) { edit_map_mode_ = b; }

void GridMap::setStartConfigRadioButton(bool b) {
    is_start_config_button_checked_ = b;
}

void GridMap::setNumberOfGrids(int n) { number_of_grids_ = n; }

int GridMap::getGridSize() const { return grid_size_; }

int GridMap::getNumberOfGrids() const { return number_of_grids_; }

QList<int> GridMap::getFreeSpaceIdxs() const { return free_space_idxs_; }

const QList<Grid *> *GridMap::getGridsList() const { return grids_; }

Grid *GridMap::getGoalGrid() const { return goal_grid_; }

Grid *GridMap::getStartGrid() const { return start_grid_; }

void GridMap::generateObstacles(int n) {
    int random_idx;
    int obst_count = 0;
    std::random_device rd;
    std::mt19937 gen(rd());
    while (obst_count < n) {
        // randomly generate index
        std::uniform_int_distribution<> dis(
                0, std::distance(free_space_idxs_.begin(), free_space_idxs_.end()) - 1);
        auto it = free_space_idxs_.begin();
        std::advance(it, dis(gen));
        random_idx = *it;

        // make the indexed grid as obstacle
        grids_->at(random_idx)->setOccupied();

        // remove index from freespace indexes list
        free_space_idxs_.removeOne(random_idx);

        // increment obstacle count
        obst_count++;
    }
}

void GridMap::clearObstacles() {
    for (int i = 0; i < grids_->size(); i++) {
        if (grids_->at(i)->isOccupied()) {
            grids_->at(i)->setFree();
            free_space_idxs_.append(i);
        }
    }
}

QColor GridMap::randomColor(){

    int r, g, b;
    QString color_value, stR, stG, stB;
    r = rand() % 200;
    g = rand() % 200;
    b = rand() % 200;
    bool ok = true;
    stR.setNum(r, 16); if (stR.toInt(&ok, 16)<16) { stR.prepend("0"); }
    stG.setNum(g, 16); if (stG.toInt(&ok, 16)<16) { stG.prepend("0"); }
    stB.setNum(b, 16); if (stB.toInt(&ok, 16)<16) { stB.prepend("0"); }
    color_value.append("#" + stR + stG + stB);

    return QColor(color_value);
}

void GridMap::render_grids(int height, int width){

    this->step = 0;
    this->height = height;
    this->width = width;

    // clear the grids
    grids_->clear();

    // clear the scene (also delete the objects)
    scene_->clear();

    // get grid size
    int v = std::max((int)(ceil(800 / height)), (int)(ceil(800 / width)));

     // setting total number of grids in the map
    number_of_grids_ = width * height;

    for (int row = 0; row < height; row++) {
         for (int col = 0; col < width; col++) {
            // create grid obj
            Grid *g = new Grid(this);

            // set pos and size
            g->setRect(0, 0, v, v);
            g->setPos(col * v,  row * v);

            grids_->append(g);
            scene_->addItem(g);

        }
    }

}


void GridMap::render_grids_obstacle(const std::vector<Position>& obstacle_v){

    clearObstacles();

    for(auto pos: obstacle_v){
        // make the indexed grid as obstacle
        int idx = pos.x + pos.y * this->height;

        grids_->at(idx)->setOccupied();
    }

}

void GridMap::renderResultGrids(const std::map<QString, std::vector<Position>>& path_map){

    this->step = 0;
    this->path_map = path_map;

    agent_color_map.clear();
    // get grid size
    int v = std::max((int)(ceil(800 / this->height)), (int)(ceil(800 / this->width)));

    for(auto iter=path_map.begin(); iter != path_map.end(); iter++){
        qDebug() << iter->first;

        QString agent_name = iter->first;
        QString agent_id = agent_name.remove(QRegExp("Agent "));
        QString agent_name_start = "A" + agent_id;

        QString agent_name_goal = "G" + agent_id;

        auto start_pos = iter->second.at(0);
        GraphicsText *start_text = new GraphicsText(this);
        start_text->setPlainText(agent_name_start);
        start_text->setPos(start_pos.x * v,  start_pos.y * v);
        scene_->addItem(start_text);

        ///
        auto goal_pos = iter->second.back();
        GraphicsText *goal_text = new GraphicsText(this);
        goal_text->setPlainText(agent_name_goal);
        goal_text->setPos(goal_pos.x * v,  goal_pos.y * v);
        scene_->addItem(goal_text);

        QColor color = randomColor();

        agent_color_map.insert(std::pair<QString, QColor>(iter->first, color));


//        int start_idx = start_pos.x + start_pos.y * this->height ;
//        int goal_idx = goal_pos.x + goal_pos.y * this->height;

        int start_idx = start_pos.x + start_pos.y * this->height;
        int goal_idx = goal_pos.x + goal_pos.y * this->height;

        grids_->at(start_idx)->setItemGridColor(color);
        grids_->at(goal_idx)->setItemGridColor(color);

//        for(auto item_pos: iter->second){
//            qDebug() << item_pos.x << " " << item_pos.y;
//
//            GraphicsText *g_text = new GraphicsText(this);
//
//            g_text->setPlainText("A0");
//            g_text->setPos(item_pos.x * v,  item_pos.y * v);
//
//            scene_->addItem(g_text);
//        }
    }

}


void GridMap::lastStep() {

    if(this->step > 1){
        this->step--;
    }

    for(auto iter=this->path_map.begin(); iter != this->path_map.end(); iter++){

        QString agent_name = iter->first;
        QColor color = QColor(255, 255, 255, 255);

        if(this->step < (iter->second.size() - 1)){
            int idx = iter->second.at(this->step).y * this->height + iter->second.at(this->step).x;
            grids_->at(idx)->setItemGridColor(color);
        }

    }
}

void GridMap::nextStep() {

//    for(auto iter=agent_color_map.begin(); iter != agent_color_map.end(); iter++){
//
//        qDebug() << iter->first;
//        qDebug() << iter->second;
//    }

    for(auto iter=this->path_map.begin(); iter != this->path_map.end(); iter++){

        QString agent_name = iter->first;
        QColor color;
        auto agent_color_iter = agent_color_map.find(agent_name);
        if(agent_color_iter != agent_color_map.end()){
            color = agent_color_iter->second;
        }

        if(this->step <= (iter->second.size() - 1)){
            int idx = iter->second.at(this->step).y * this->height + iter->second.at(this->step).x;
            grids_->at(idx)->setItemGridColor(color);
        }

//        qDebug() << iter->second.size();

    }

    this->step++;

}

void GridMap::renderGrids(int grid_size) {
    setGridSize(grid_size);

    // clear the grids
    grids_->clear();

    // clear free space indexes
    free_space_idxs_.clear();

    // clear start and goal grid ptrs
    start_grid_ = nullptr;
    goal_grid_ = nullptr;

    // clear the scene (also delete the objects)
    scene_->clear();

    // get grid size from slider value
    int v = grid_size_;
    v = (int)(ceil(v / 5.0) * 5);
    int no_of_row_grids_ = (int)(ceil(500.0 / v));

    // setting total number of grids in the map
    setNumberOfGrids(no_of_row_grids_ * no_of_row_grids_);

    int pos_offset = -1; // -5
    int free_space_idx = 0;
    for (int col = 0; col < no_of_row_grids_; col++) {
        for (int row = 0; row < no_of_row_grids_; row++) {
            // create grid obj
            Grid *g = new Grid(this);

            // set pos and size
            g->setRect(0, 0, v, v);
            g->setPos(pos_offset + row * v, pos_offset + col * v);
            grids_->append(g);
            scene_->addItem(g);
            free_space_idxs_.append(free_space_idx);
            free_space_idx++;
        }
    }

//     find neighbour indexes for each grid
//    for (int col = 0; col < no_of_row_grids_; col++) {
//        for (int row = 0; row < no_of_row_grids_; row++) {
//            int node_idx = no_of_row_grids_ * col + row;
//            if (row > 0)
//                grids_->at(node_idx)->setNeighbourIdx(col * no_of_row_grids_ +
//                                                      (row - 1));
//            if (row < (no_of_row_grids_ - 1))
//                grids_->at(node_idx)->setNeighbourIdx(col * no_of_row_grids_ +
//                                                      (row + 1));
//            if (col > 0)
//                grids_->at(node_idx)->setNeighbourIdx((col - 1) * no_of_row_grids_ +
//                                                      row);
//            if (col < (no_of_row_grids_ - 1))
//                grids_->at(node_idx)->setNeighbourIdx((col + 1) * no_of_row_grids_ +
//                                                      row);
//        }
//    }

    // default start (top-left) and goal (bottom-right) configurations
//    int start_idx = 0;
//    int goal_idx =
//            no_of_row_grids_ * (no_of_row_grids_ - 1) + (no_of_row_grids_ - 1);
//    start_grid_ = grids_->at(start_idx);
//    start_grid_->setStart();
//    goal_grid_ = grids_->at(goal_idx);
//    goal_grid_->setGoal();

//    free_space_idxs_.removeOne(start_idx);
//    free_space_idxs_.removeOne(goal_idx);
}

void GridMap::isGridClicked(Grid *grid) {
    // find the index of the grid
    int idx = grids_->indexOf(grid);

    // add/remove obstacles
    if (edit_map_mode_) {
        // if either place at start or goal, just return
        if (grid == start_grid_ || grid == goal_grid_) return;

        if (grid->isOccupied()) {
            grid->setFree();
            // free space now
            // append this grid index into free space indexes
            free_space_idxs_.append(idx);
        } else {
            grid->setOccupied();
            // otherwise, remove
            free_space_idxs_.removeOne(idx);
        }
    }
        // set start & goal configs
    else if (place_config_mode_) {
        // if place at obst grid, just return
        if (grid->isOccupied()) return;

        // if either place at start or goal, just return
        if (grid == start_grid_ || grid == goal_grid_) return;

        // if start config radio button is checked
        if (is_start_config_button_checked_) {
            // make previous start grid to be empty
            if (start_grid_) {
                start_grid_->setFree();
                free_space_idxs_.append(grids_->indexOf(start_grid_));
            }
            // make this grid to be start grid
            grid->setStart();
            free_space_idxs_.removeOne(idx);
            start_grid_ = grid;
        } else {
            // make previous goal grid to be empty
            if (goal_grid_) {
                goal_grid_->setFree();
                free_space_idxs_.append(grids_->indexOf(goal_grid_));
            }
            // make this grid to be goal grid
            grid->setGoal();
            free_space_idxs_.removeOne(idx);
            goal_grid_ = grid;
        }
    }
}

void GridMap::test(){

    int height = 32;
    int width = 32;

    // clear the grids
//    ellipse_->clear();

    // clear the scene (also delete the objects)
    scene_->clear();

    // get grid size
    int v = std::max((int)(ceil(800 / height)), (int)(ceil(800 / width)));

    // setting total number of grids in the map
    number_of_grids_ = width * height;

    for (int col = 0; col < width; col++) {
        for (int row = 0; row < height; row++) {
            // create grid obj
            Grid *g = new Grid(this);

            // set pos and size
            g->setRect(0, 0, v, v);
            g->setPos(row * v,  col * v);

//            grids_->append(g);
            scene_->addItem(g);

            // create grid obj
//            Ellipse *g = new Ellipse(this);
//
//            // set pos and size
//            g->setRect(0, 0, v, v);
//            g->setPos(row * v,  col * v);
//
////            ellipse_->append(g);
//            scene_->addItem(g);

            QGraphicsTextItem* t = new QGraphicsTextItem();

            t->setPlainText("A0");
            t->setPos(row * v,  col * v);

            scene_->addItem(t);


        }
    }
}