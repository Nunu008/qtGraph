#include <QPen>
#include <QGraphicsItem>
#include <QPainter>
#include <QMap>
#include <QDebug>




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
public:

    bool Pressed;

    bool startOrEnd;
    QGraphicsLineItem *customLine;

    QMap<QGraphicsLineItem*, bool> customLineList;

    QPointF mCenter;
    QString mName;

    enum ManagedLineEnd {
        StartOfLine,
        EndOfLine
    };
    ManagedLineEnd m_myLineEnd;
};

