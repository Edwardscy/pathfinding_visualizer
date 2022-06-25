//
// Created by ed on 6/23/22.
//

#ifndef PATHFINDING_VISUALIZER_PARSE_DATA_H
#define PATHFINDING_VISUALIZER_PARSE_DATA_H

#include <QTextStream>
#include <QString>
#include <QDebug>

#include <vector>

#include "custom_data.h"

#include "json.hpp"


using json = nlohmann::json;



void parse_map_data(QTextStream &in);



class ParseMapData
{
public:
    ParseMapData();
    ~ParseMapData();

public:
    void parse(QTextStream &in);

    void print_map_infos();

public:
    const int& get_height() { return height;}
    const int& get_width() { return width;}
    const std::vector<Position>& get_obstacle_v() { return obstacle_v;}
private:
    QString type;
    int height;
    int width;
    std::vector<Position> obstacle_v;

};







#endif //PATHFINDING_VISUALIZER_PARSE_DATA_H
