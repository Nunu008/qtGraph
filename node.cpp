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
        qDebug()<< neighbours.count();
    }
    qDebug() << nodeSetLocal.count();


    nodeSetLocal.insert(0,tgt);


    if(!label.startsWith("_rev_"))
    {
        tgt.createEdge("_rev_"+label, *this);
    }

}

