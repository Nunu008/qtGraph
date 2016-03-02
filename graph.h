#ifndef GRAPH_H
#define GRAPH_H

#include "nodeset.h"
#include "dialog.h"

class Graph : public Node
{
public:
    Graph();

private:
    NodeSet nodes;

public:
    Node *createNode(QString name);
    void createEdge(Node *src, const QString & label, Node  *tgt);
    void removeEdge(Node *src, const QString & label, Node  *tgt);

    Graph *clone();
    NodeSet getNodes();
private:
    static long maxId;
    bool isGraph;

};

#endif // GRAPH_H
