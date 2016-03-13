#ifndef CUSTOMITEM_H
#define CUSTOMITEM_H

#include <QPen>
#include <QGraphicsItem>
#include <QPainter>
#include <QHash>
#include <QDebug>
#include <QGraphicsScene>

#include <nodeset.h>

class NodeSet;

class CustomItem : public QGraphicsItem
{
public:
    CustomItem();

    QRectF boundingRect() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent* e );

    void setLine(QGraphicsLineItem *newLine, bool side);
    void setGroup(QGraphicsItemGroup *group);

    qreal getXPosEllipse();
    qreal getYPosEllipse();

    void doCollision();
    void refreshEdges();

    void setNeighbours(QHash<QString, NodeSet> neighbours);
    QHash<QString, NodeSet> getNeighbours();
    void refreshTreeView();
    void setGraph();


public:
    bool Pressed;

    bool startOrEnd;
    QGraphicsLineItem * customLine;

    QHash<QGraphicsLineItem*, bool> customLineList;

    QPointF mCenter;
    QString mName;
    QRectF ellipse;
    QGraphicsItemGroup *customItemGroup;
    bool isGraph;
    bool isGroupped;

    QHash<QString,NodeSet> neighboursEllipse ;

    enum ManagedLineEnd {
        StartOfLine,
        EndOfLine
    };
    ManagedLineEnd m_myLineEnd;


    enum ManagedShape{
        Node,
        Graph
    };
    ManagedShape m_myShape;

};

#endif // CUSTOMITEM_H
