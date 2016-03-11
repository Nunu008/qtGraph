#include "customitem.h"
#include "nodeset.h"
#include "dialog.h"


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

    isGraph    = false;
    isGroupped = false;

    customItemGroup = NULL;
}

QRectF CustomItem::boundingRect() const
{
    //outer most edges
    return QRectF(0,0,75,75);
}

void CustomItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    if(isGraph == false)
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
    }

    if(isGraph == true)
    {
        painter->setBrush(Qt::white);

        if(Pressed)
        {
            QPen pen(Qt::red, 0.5);
            painter->setPen(pen);
        }
        else
        {
            QPen pen(Qt::black, 0.5);
            painter->setPen(pen);
        }

        painter->drawRoundRect(ellipse);
    }

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

void CustomItem::mouseDoubleClickEvent(QGraphicsSceneMouseEvent* e )
{
    if(isGraph == true)
    {
        isGroupped = !isGroupped;
        qDebug()<<"doubleclick: isGroupped: "<< isGroupped;

        customItemGroup->setHandlesChildEvents(isGroupped);
    }
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

void CustomItem::setNeighbours(QHash<QString, NodeSet> neighbours)
{
    neighboursEllipse = neighbours;
}

QHash<QString,NodeSet>  CustomItem::getNeighbours()
{
    return neighboursEllipse;
}

void CustomItem::refreshTreeView()
{

    //Dialog::qhashModel->clear();
    //Dialog::qhashModel->setColumnCount(2);
    //Dialog::qhashModel->setRowCount(20);

    MainWindow::qhashModel->clear();
    MainWindow::qhashModel->setColumnCount(2);
    MainWindow::qhashModel->setRowCount(20);

    QStringList header;
    header<< "ID"<<"Node label";
    //Dialog::qhashModel->setHorizontalHeaderLabels(header);
    MainWindow::qhashModel->setHorizontalHeaderLabels(header);


    int i=0;
    QHashIterator<QString,NodeSet> Iter(this->getNeighbours());
    while(Iter.hasNext())
    {
          Iter.next();
//          QHashIterator<int,Node*> Iter2(Iter.value());
//        while(Iter2.hasNext())
//        {
//            Iter2.next();
//            Dialog::qhashModel->setData(Dialog::qhashModel->index(i, 0),Iter2.key());
//            Dialog::qhashModel->setData(Dialog::qhashModel->index(i, 1),Iter2.value()->getLabel());
//            i++;
//        }
    }

}

void CustomItem::setGraph()
{
    isGraph =true;
}

void CustomItem::setGroup(QGraphicsItemGroup *group)
{
    customItemGroup = group;
}

