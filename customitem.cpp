#include "customitem.h"
#include "nodeset.h"

CustomItem::CustomItem()
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

QRectF CustomItem::boundingRect() const
{
    //outer most edges
    return QRectF(0,0,75,75);
}

void CustomItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::gray);

    if(Pressed)
    {
        QPen pen(Qt::red, 3);
        painter->setPen(pen);

    }
    else
    {
        QPen pen(Qt::black, 3);
        painter->setPen(pen);
    }

    painter->drawEllipse(ellipse);
    painter->drawText(mCenter,mName);
}

qreal CustomItem::getXPosEllipse()
{
    return this->scenePos().x();
}
qreal CustomItem::getYPosEllipse()
{
    return this->scenePos().y();
}

void CustomItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Pressed = true;


    refreshEdges();

    refreshTreeView();

    update();
    QGraphicsItem::mousePressEvent(event);

}

void CustomItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Pressed = false;

    refreshEdges();

    update();
    QGraphicsItem::mouseReleaseEvent(event);
}


void CustomItem::setLine(QGraphicsLineItem *newLine, bool side)
{
    customLineList.insert(newLine,side);

    customLine = newLine;
    startOrEnd = side;
}


void CustomItem::doCollision()
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

void CustomItem::refreshEdges()
{
    QHashIterator<QGraphicsLineItem*, bool> Iter(customLineList);

    while(Iter.hasNext())
    {
        Iter.next();

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

void CustomItem::setNeighbours(QHash<QString,NodeSet> *neighbours)
{
    neighboursEllipse = neighbours;
}

void CustomItem::refreshTreeView()
{
    //QHash<QString,NodeSet> nE = *neighboursEllipse;



    //QHashIterator<QString,NodeSet> Iter( *neighboursEllipse);
    /*
       while(Iter.hasNext())
       {
        Iter.next();

        //qhashModel->setData(qhashModel->index(i, 0), Iter.value());
        //i++;

        // typ of edge
        qDebug()<<Iter.key();

        // label of neighbours
//        foreach(int i,Iter.value().keys())
//        {
//            qDebug()<< Iter.value()[i].label;
//        }

    }
*/
}
