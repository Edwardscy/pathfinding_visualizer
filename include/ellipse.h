//
// Created by ed on 6/25/22.
//

#ifndef PATHFINDING_VISUALIZER_ELLIPSE_H
#define PATHFINDING_VISUALIZER_ELLIPSE_H

#include <QObject>
#include <QGraphicsEllipseItem>
#include <QDebug>



class Ellipse : public QObject, public QGraphicsEllipseItem {
Q_OBJECT
public:
    /** \brief Constructor. */
    Ellipse(QObject *parent = nullptr);

    /** \brief Destructor. */
    ~Ellipse();
};


#endif //PATHFINDING_VISUALIZER_ELLIPSE_H
