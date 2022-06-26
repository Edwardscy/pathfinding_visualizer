//
// Created by ed on 6/26/22.
//

#ifndef PATHFINDING_VISUALIZER_GRAPHIC_TEXT_H
#define PATHFINDING_VISUALIZER_GRAPHIC_TEXT_H


#include <QBrush>
#include <QGraphicsDropShadowEffect>
#include <QGraphicsTextItem>
#include <QGraphicsSceneMouseEvent>
#include <QList>
#include <QObject>
#include <iostream>


class GraphicsText : public QGraphicsTextItem {
    Q_OBJECT
public:
    /** \brief Constructor. */
    GraphicsText(QObject *parent = nullptr);

    /** \brief Destructor. */
    ~GraphicsText();
};

#endif //PATHFINDING_VISUALIZER_GRAPHIC_TEXT_H
