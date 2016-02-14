#ifndef NODESET_H
#define NODESET_H

#include <QHash>
#include <QHashNode>
#include "node.h"

class Node;

class NodeSet : public QHash<int,Node>
{
public:
    NodeSet();

};

#endif // NODESET_H
