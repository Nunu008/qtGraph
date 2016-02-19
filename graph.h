#ifndef GRAPH_H
#define GRAPH_H

#include <QGraphicsScene>
#include <QGraphicsItem>

#include "node.h"
#include "nodeset.h"

class Graph
{
public:
    Graph();

    Node createNode(QString name, long newId);
    void createEdge(Node src, QString label, Node tgt);

    void refreshNodesEdges();


    void test1();
    void test2();
    void test3();

private:

    QGraphicsScene *scene;

    static long maxIdNodeGraph;

    NodeSet nodes;

    Node node;

};

#endif // GRAPH_H
