#include "customitem.h"

customItem::customItem()
{
    Pressed = false;
    setFlag(ItemIsMovable);
    customLine = NULL;

    ellipse = boundingRect();
    mCenter = ellipse.center();


    // random start position
    int startX = 0;
    int startY = 0;


    if(qrand() % 1)
    {
        startX = qrand() % 500;
        startY = qrand() % 500;
    }
    else
    {
        startX = qrand() % -500;
        startY = qrand() % -500;
    }

    setPos(mapToParent(startX, startY));



}

QRectF customItem::boundingRect() const
{
    // outer most edges
    return QRectF(0,0,75,75);
}

void customItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //QRectF ellipse = boundingRect();
    //mCenter = ellipse.center();

    painter->setBrush(Qt::gray);



    if(Pressed)
    {
        QPen pen(Qt::red, 3);
        painter->setPen(pen);
        //painter->drawEllipse(ellipse);
        //painter->drawText(mCenter,mName);

    }
    else
    {
        QPen pen(Qt::black, 3);
        painter->setPen(pen);
        //painter->drawEllipse(ellipse);
        //painter->drawText(mCenter,mName);
    }


    painter->drawEllipse(ellipse);
    painter->drawText(mCenter,mName);
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
/*
    QHashIterator<QGraphicsLineItem*, bool> Iter(customLineList);

    while(Iter.hasNext())
    {
        Iter.next();
        //qDebug()<< "_________________________________________________";
        //qDebug()<< "mousePressEvent: " << Iter.key()<< " = " << Iter.value();

        if(Iter.value() == false)
        {
            Iter.key()->setLine(this->scenePos().x() + mCenter.x(),this->scenePos().y()+ mCenter.y(),
                                Iter.key()->line().x2(),Iter.key()->line().y2());
        }
        if(Iter.value() == true )
        {
            Iter.key()->setLine(Iter.key()->line().x1(),Iter.key()->line().y1(),
                                this->scenePos().x() + mCenter.x(),this->scenePos().y()+ mCenter.y());
        }
    }
*/
    refreshEdges();
    update();
    QGraphicsItem::mousePressEvent(event);

}

void customItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Pressed = false;
/*
    QHashIterator<QGraphicsLineItem*, bool> Iter(customLineList);

    while(Iter.hasNext())
    {
        Iter.next();
        //qDebug()<< "_________________________________________________";
        //qDebug()<< "mouseReleaseEvent: " << Iter.key()<< " = " << Iter.value();

        if(Iter.value() == false)
        {
            Iter.key()->setLine(this->scenePos().x() + mCenter.x(),this->scenePos().y()+ mCenter.y(),
                                Iter.key()->line().x2(),Iter.key()->line().y2());
        }
        if(Iter.value() == true )
        {
            Iter.key()->setLine(Iter.key()->line().x1(),Iter.key()->line().y1(),
                                this->scenePos().x() + mCenter.x(),this->scenePos().y()+ mCenter.y());
        }
    }
*/
    refreshEdges();

    update();
    QGraphicsItem::mouseReleaseEvent(event);
}


void customItem::setLine(QGraphicsLineItem *newLine, bool side)
{
    //qDebug() << "-------------------------------------------";
    //qDebug() << "&customLine:\t" << &customLine << "\t&newLine:\t" << &newLine;
    //qDebug() << "customLine:\t" << customLine << "\tnewLine:\t" << newLine;

    customLineList.insert(newLine,side);

    customLine = newLine;
    startOrEnd = side;



    //qDebug() << "customLine:\t" << customLine << "\tnewLine:\t" << newLine;
}


void customItem::doCollision()
{
    // get a new postion


    // check if the new position is in bounds
    QPointF newPoint = mapToParent(-(boundingRect().width()), -(boundingRect().width() + 2));

    if(!scene()->sceneRect().contains((newPoint)))
    {
        //move pack in bounds
        newPoint   = mapToParent(0,0);
    }
    else
    {
        // set the new position
        setPos(newPoint);
    }
}

void customItem::refreshEdges()
{
    QHashIterator<QGraphicsLineItem*, bool> Iter(customLineList);

    while(Iter.hasNext())
    {
        Iter.next();
        //qDebug()<< "_________________________________________________";
        //qDebug()<< "mousePressEvent: " << Iter.key()<< " = " << Iter.value();

        if(Iter.value() == false)
        {
            Iter.key()->setLine(this->scenePos().x() + mCenter.x(),this->scenePos().y()+ mCenter.y(),
                                Iter.key()->line().x2(),Iter.key()->line().y2());
        }
        if(Iter.value() == true )
        {
            Iter.key()->setLine(Iter.key()->line().x1(),Iter.key()->line().y1(),
                                this->scenePos().x() + mCenter.x(),this->scenePos().y()+ mCenter.y());
        }
    }
}
