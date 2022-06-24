//
// Created by ed on 6/23/22.
//

#include "parse_data.h"


void parse_map_data(QTextStream &in){

    bool is_line_null = false;
    while (!is_line_null){
        QString line = in.readLine();

        if(line.isNull()){
            is_line_null = true;
        }
        else{
            if(line == "map"){
                qDebug() << "dsdsdsd";
            }
            qDebug() << line;
        }
    }
}


ParseMapData::ParseMapData() {

}


ParseMapData::~ParseMapData() {

}

void ParseMapData::parse(QTextStream &in){

    int count = 0;
    bool is_line_null = false;
    while (!is_line_null){
        QString line = in.readLine();


        if(line.isNull()){
            is_line_null = true;
        }
        else{

            if(line.contains("type ")){

                QString s = line;
                s = s.remove("type ");
                type = s;

            }
            else if(line.contains("height ")){

                QString s = line;
                s = s.remove("height ");
                height = s.toInt();

            }
            else if(line.contains("width ")){

                QString s = line;
                s = s.remove("width ");
                width = s.toInt();

            }
            else if(line.contains("@") || line.contains(".")){

//                QString s = line;
//                s = s.remove("width ");
//                width = s.toInt();

                qDebug() << line;

            }

//            qDebug() << line;
            count++;
        }
    }
    qDebug() << "count: " << count;
}


