#ifndef GRAPH_H
#define GRAPH_H

#include "nodeset.h"
#include "dialog.h"

class Graph
{
public:
    Graph();

private:
    NodeSet nodes;

public:
    Node createNode(QString name);
    void createEdge(Node scr, QString label, Node tgt);

private:
    static long maxId;

};

#endif // GRAPH_H
