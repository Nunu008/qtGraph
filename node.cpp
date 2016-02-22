#include "node.h"

Node::Node()
{

}

void Node::setId(const long &value)
{
    id = value;
}

void Node::createEdge(QString label, Node tgt)
{
    NodeSet nodeSetLocal = this->neighbours[label];

    if(nodeSetLocal.isEmpty())
    {
        neighbours.insert(label,nodeSetLocal);
    }

    nodeSetLocal.insert(0,tgt);

    if(!label.startsWith("_rev_"))
    {
        tgt.createEdge("_rev_"+label, *this);
    }

}

void Node::setLabel(QString label)
{
    this->label = label;
}


NodeSet Node::getNeighbours(QString label)
{
    if(!neighbours.empty())
    {
     return neighbours[label];
    }

    return neighbours[label];

}

QString Node::getNodeAttribute(QString attrName)
{
    return nodeAttribute[attrName];
}

void Node::setNodeAttribute(QString attrName, QString value)
{
    nodeAttribute.insert(attrName,value);
}


