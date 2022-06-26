//
// Created by ed on 6/25/22.
//

#ifndef PATHFINDING_VISUALIZER_PATH_H
#define PATHFINDING_VISUALIZER_PATH_H

#include <QBrush>
#include <QGraphicsDropShadowEffect>
#include <QGraphicsPathItem>
#include <QGraphicsSceneMouseEvent>
#include <QList>
#include <QObject>
#include <iostream>


class Path : public QObject, public QGraphicsPathItem {
Q_OBJECT
public:
    /** \brief Constructor. */
    Path(QObject *parent = nullptr);

    /** \brief Destructor. */
    ~Path();
};

#endif //PATHFINDING_VISUALIZER_PATH_H
