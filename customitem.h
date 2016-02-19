#include <QPen>
#include <QGraphicsItem>
#include <QPainter>
#include <QHash>
#include <QDebug>

#include <QGraphicsScene>



class customItem : public QGraphicsItem
{
public:
    customItem();

    QRectF boundingRect() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

    void setLine(QGraphicsLineItem *newLine, bool side);

    qreal getXPosEllipse();
    qreal getYPosEllipse();

    void doCollision();
    void refreshEdges();
public:

    bool Pressed;

    bool startOrEnd;
    QGraphicsLineItem *customLine;

    QHash<QGraphicsLineItem*, bool> customLineList;

    QPointF mCenter;
    QString mName;
    QRectF ellipse;

    enum ManagedLineEnd {
        StartOfLine,
        EndOfLine
    };
    ManagedLineEnd m_myLineEnd;

private:
    qreal angle, speed;
};

