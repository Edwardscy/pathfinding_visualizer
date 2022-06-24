//
// Created by ed on 6/24/22.
//

#ifndef PATHFINDING_VISUALIZER_PARSE_RESULT_DATA_H
#define PATHFINDING_VISUALIZER_PARSE_RESULT_DATA_H


#include <QTextStream>
#include <QString>
#include <QDebug>

#include "custom_data.h"

class ParseResultData
{
public:
    ParseResultData();
    ~ParseResultData();

public:
    void parse(QTextStream &in);

    void print_map_infos();
private:
//    QString type;
//    int height;
//    int width;
//    std::vector<Position> obstacle_v;

};





#endif //PATHFINDING_VISUALIZER_PARSE_RESULT_DATA_H
