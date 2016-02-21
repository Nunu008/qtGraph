#ifndef NODE_H
#define NODE_H

#include <QHash>

#include "nodeset.h"
#include "customitem.h"

class NodeSet;

class Node
{
public:
    Node();
    void setId(const long &value);
    void createEdge(QString label, Node tgt);

private:
    long id;
    QHash<QString,NodeSet> neighbours;


public:
    CustomItem *ellipse;
};

#endif // NODE_H
