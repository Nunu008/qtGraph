#include "customitem.h"

customItem::customItem()
{
    Pressed = false;
    setFlag(ItemIsMovable);

}

QRectF customItem::boundingRect() const
{
    // outer most edges
    return QRectF(0,0,100,100);
}

void customItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF ellipse = boundingRect();

    mCenter = ellipse.center();

    //qDebug()  << "mCenter: " << mCenter;

    if(Pressed)
    {
        QPen pen(Qt::red, 3);
        painter->setPen(pen);
        painter->drawEllipse(ellipse);
    }
    else
    {
        QPen pen(Qt::black, 3);
        painter->setPen(pen);
        painter->drawEllipse(ellipse);
    }
}



qreal customItem::getXPosEllipse()
{
    return this->scenePos().x();
}
qreal customItem::getYPosEllipse()
{
    return this->scenePos().y();
}

void customItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Pressed = true;
    update();
    QGraphicsItem::mousePressEvent(event);

}

void customItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Pressed = false;

    if(startOrEnd == false)
    {
       customLine->setLine( this->scenePos().x() + mCenter.x(),this->scenePos().y()+ mCenter.y(),
                            customLine->line().x2(), customLine->line().y2() );
    }


    if(startOrEnd == true)
    {
       customLine->setLine( customLine->line().x1(), customLine->line().y1(),
                            this->scenePos().x() + mCenter.x(),this->scenePos().y()+ mCenter.y());
    }

    update();
    QGraphicsItem::mouseReleaseEvent(event);
}


void customItem::setLine(QGraphicsLineItem *newLine, bool side)
{
    qDebug() << "-------------------------------------------";
    qDebug() << "&customLine:\t" << &customLine << "\t&newLine:\t" << &newLine;
    qDebug() << "customLine:\t" << customLine << "\tnewLine:\t" << newLine;

    customLine = newLine;
    startOrEnd = side;

    qDebug() << "customLine:\t" << customLine << "\tnewLine:\t" << newLine;
}
