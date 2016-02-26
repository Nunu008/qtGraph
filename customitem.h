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

    void setLine(QGraphicsLineItem *newLine, bool side);

    qreal getXPosEllipse();
    qreal getYPosEllipse();

    void doCollision();
    void refreshEdges();

    void setNeighbours(QHash<QString,NodeSet> *neighbours);
    void refreshTreeView();

private:
    qreal angel, speed;

public:
    bool Pressed;

    bool startOrEnd;
    QGraphicsLineItem * customLine;

    QHash<QGraphicsLineItem*, bool> customLineList;

    QPointF mCenter;
    QString mName;
    QRectF ellipse;

    QHash<QString,NodeSet> *neighboursEllipse ;

    enum ManagedLineEnd {
        StartOfLine,
        EndOfLine
    };
    ManagedLineEnd m_myLineEnd;



};

#endif // CUSTOMITEM_H
