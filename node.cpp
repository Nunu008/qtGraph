#include "node.h"

Node::Node()
{

}

void Node::setId(const long &value)
{
    id = value;
}

long Node::getId()
{
    return id;
}



void Node::createEdge(const QString & label, Node & tgt)
{


    NodeSet nodeSetLocal = neighbours[label];


    if(nodeSetLocal.isEmpty())
    {
        nodeSetLocal.insert(tgt.getId(),tgt);
        neighbours.insert(label,nodeSetLocal);
    }

    nodeSetLocal.insert(tgt.getId(),tgt);

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


