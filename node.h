#ifndef NODE_H
#define NODE_H


#include "customitem.h"

class Node
{
public:
    Node();
    void setId(const long &value);
    void createEdge(QString label, Node tgt);

private:
    long id;

public:
    CustomItem *ellipse;
};

#endif // NODE_H
