//
// Created by ed on 6/24/22.
//

#include "parse_result_data.h"



ParseResultData::ParseResultData(){

}

ParseResultData::~ParseResultData(){

}

void ParseResultData::parse(QTextStream &in) {

    bool is_line_null = false;
    while (!is_line_null) {
        QString line = in.readLine();


        if (line.isNull()) {
            is_line_null = true;
        } else {


            QRegExp agent_name_rx("^Agent \\d?");
            agent_name_rx.indexIn(line);
            QString agent_name = agent_name_rx.cap(0);

            qDebug() << agent_name;
            QRegExp agent_path_rx("\\(\\d*,\\d*\\)");

            for(int nPos=0; nPos = agent_path_rx.indexIn(line, nPos), nPos>=0; nPos+=agent_path_rx.matchedLength())
            {
                QString path_str = agent_path_rx.cap(0);
                parse_item_pos(path_str);
            }


//            if(agent_name == "Agent 9"){
//                qDebug() << agent_name;
//                QRegExp agent_path_rx("\\(\\d*,\\d*\\)");
//
//                for(int nPos=0; nPos = agent_path_rx.indexIn(line, nPos), nPos>=0; nPos+=agent_path_rx.matchedLength())
//                {
////                    qDebug()<<nPos; //return index
////                    qDebug() << agent_path_rx.cap(0);//return string that match
//
//                    QString path_str = agent_path_rx.cap(0);
//                    parse_item_pos(path_str);
//                }
//            }




        }
    }
}


void ParseResultData::parse_item_pos(QString path_str){

    QRegExp rx("(\\d+)");

    int x{0};
    int y{0};

    int n_pos = rx.indexIn(path_str, 0);
    x = rx.cap(0).toInt();

    rx.indexIn(path_str, n_pos + rx.matchedLength());
    y = rx.cap(0).toInt();

    qDebug() << path_str << "x: " << x << "y: " << y;



}


void ParseResultData::print_map_infos(){

}
