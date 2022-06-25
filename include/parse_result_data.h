//
// Created by ed on 6/24/22.
//

#ifndef PATHFINDING_VISUALIZER_PARSE_RESULT_DATA_H
#define PATHFINDING_VISUALIZER_PARSE_RESULT_DATA_H


#include <QTextStream>
#include <QString>
#include <QDebug>

#include <map>

#include "custom_data.h"



class ParseResultData
{
public:
    ParseResultData();
    ~ParseResultData();

public:
    void parse(QTextStream &in);
    Position parse_item_pos(QString path_str);

    void print_map_infos();

public:
    const std::map<QString, std::vector<Position>>& get_path_map() { return path_map;}

private:
    std::map<QString, std::vector<Position>> path_map;


};





#endif //PATHFINDING_VISUALIZER_PARSE_RESULT_DATA_H
