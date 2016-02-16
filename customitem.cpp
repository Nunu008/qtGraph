#include "customitem.h"

customItem::customItem()
{
    Pressed = false;
    setFlag(ItemIsMovable);
    customLine = NULL;

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

    painter->setBrush(Qt::gray);


    if(Pressed)
    {
        QPen pen(Qt::red, 3);
        painter->setPen(pen);
        painter->drawEllipse(ellipse);
        painter->drawText(mCenter,mName);

    }
    else
    {
        QPen pen(Qt::black, 3);
        painter->setPen(pen);
        painter->drawEllipse(ellipse);
        painter->drawText(mCenter,mName);
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

    QHashIterator<QGraphicsLineItem*, bool> Iter(customLineList);

    while(Iter.hasNext())
    {
        Iter.next();
        qDebug()<< "setLine: " << Iter.key()<< " = " << Iter.value();

        if(Iter.value() == false)
        {
            Iter.key()->setLine(this->scenePos().x() + mCenter.x(),this->scenePos().y()+ mCenter.y(),
                                customLine->line().x2(), customLine->line().y2());
        }
        if(Iter.value() == true )
        {
            Iter.key()->setLine(customLine->line().x1(), customLine->line().y1(),
                                this->scenePos().x() + mCenter.x(),this->scenePos().y()+ mCenter.y());
        }
    }




    update();
    QGraphicsItem::mousePressEvent(event);

}

void customItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Pressed = false;

    QHashIterator<QGraphicsLineItem*, bool> Iter(customLineList);

    while(Iter.hasNext())
    {
        Iter.next();
        qDebug()<< "setLine: " << Iter.key()<< " = " << Iter.value();

        if(Iter.value() == false)
        {
            Iter.key()->setLine(this->scenePos().x() + mCenter.x(),this->scenePos().y()+ mCenter.y(),
                                customLine->line().x2(), customLine->line().y2());
        }
        if(Iter.value() == true )
        {
            Iter.key()->setLine(customLine->line().x1(), customLine->line().y1(),
                                this->scenePos().x() + mCenter.x(),this->scenePos().y()+ mCenter.y());
        }
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

    customLineList.insert(newLine,side);

    qDebug() << "customLine:\t" << customLine << "\tnewLine:\t" << newLine;
}
