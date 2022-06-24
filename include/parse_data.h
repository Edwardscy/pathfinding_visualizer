//
// Created by ed on 6/23/22.
//

#ifndef PATHFINDING_VISUALIZER_PARSE_DATA_H
#define PATHFINDING_VISUALIZER_PARSE_DATA_H

#include <QTextStream>
#include <QString>
#include <QDebug>

#include <vector>

#include "json.hpp"


using json = nlohmann::json;



void parse_map_data(QTextStream &in);

struct Position{
    Position(int x, int y){
        this->x = x;
        this->y = y;
    }

    int x;
    int y;
};

class ParseMapData
{
public:
    ParseMapData();
    ~ParseMapData();

public:
    void parse(QTextStream &in);

    void print_map_infos();
private:
    QString type;
    int height;
    int width;
    std::vector<Position> obstacle_v;

};






#endif //PATHFINDING_VISUALIZER_PARSE_DATA_H
