#include "node.h"

Node::Node()
{

}
void Node::setEllipseIsMoveable()
{
    ellipse->setFlag(QGraphicsItem::ItemIsMovable);
}
void Node::setEllipseIsSelectable()
{
    ellipse->setFlag(QGraphicsItem::ItemIsSelectable);
}

long Node::getId() const
{
    return id;
}

void Node::setId(const long &value)
{
    id = value;
}

void Node::createEdge(QString label, Node tgt)
{
//    customItem->customLine = new QGraphicsLineItem (this->ellipse->scenePos().x() + this->ellipse->mCenter.x(),
//                                                   this->ellipse->scenePos().y() + this->ellipse->mCenter.y(),
//                                                   tgt.ellipse->scenePos().x() + tgt.ellipse->mCenter.x(),
//                                                   tgt.ellipse->scenePos().y() + tgt.ellipse->mCenter.y());

}




