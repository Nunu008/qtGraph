#include "node.h"

Node::Node()
{

}

Node::~Node()
{
    qDebug()<<"Node "<< getId() << " deletet";
}


void Node::setId(const long &value)
{
    id = value;
}

long Node::getId()
{
    return id;
}


void Node::createEdge(const QString & label, Node *tgt)
{
    NodeSet nodeSetLocal;

    nodeSetLocal = neighbours[label];


    if(nodeSetLocal.isEmpty())
    {
        nodeSetLocal.insert(tgt->getId(),tgt);
        neighbours.insert(label,nodeSetLocal);
    }

    nodeSetLocal.insert(tgt->getId(),tgt);
    neighbours.insert(label,nodeSetLocal);

    if(!label.startsWith("_rev_"))
    {
        tgt->createEdge("_rev_"+label, this);
    }

}

void Node::removeEdge(const QString & label, Node *tgt)
{
    NodeSet nodeSetLocal;

    nodeSetLocal = neighbours[label];


    if(nodeSetLocal.isEmpty())
    {
        return;
    }

    if(nodeSetLocal.contains(tgt->getId()))
    {
        nodeSetLocal.remove(tgt->getId());
        neighbours.insert(label,nodeSetLocal);

        tgt->removeEdge("_rev_" + label,this);
    }


}

void Node::setLabel(QString label)
{
    this->label = label;
}

QString Node::getLabel()const
{
    return label ;
}
/*
QHash<QString,NodeSet> *Node::getNeighbours()
{
    return &neighbours;
}
*/
QHash<QString,NodeSet> Node::getNeighbours() const
{
    return neighbours;
}

NodeSet Node::getNeighbours(QString label)
{
    if(!neighbours.empty())
    {
     return neighbours[label];
    }

    return neighbours[label];

}
QHash<QString, QString> Node::getNodeAttribute() const
{
    return nodeAttribute;
}

QString Node::getNodeAttribute(QString attrName) const
{
    return nodeAttribute[attrName];
}

void Node::setNodeAttribute(QString attrName, QString value)
{
    nodeAttribute.insert(attrName,value);
}


