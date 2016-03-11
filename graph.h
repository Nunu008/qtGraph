#ifndef GRAPH_H
#define GRAPH_H

#include "nodeset.h"
//#include "dialog.h"
#include "mainwindow.h"

class Graph : public Node
{
public:
    Graph();

private:
    NodeSet nodes;
    QGraphicsItemGroup *group;
    bool isGroupped;

public:
    Node *createNode(QString name);
    void createEdge(Node *src, const QString & label, Node  *tgt);
    void removeEdge(Node *src, const QString & label, Node  *tgt);
    void refreshNodeEdges();

    Graph *clone();
    NodeSet getNodes();

    QGraphicsItemGroup *getGroup() const;

    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *e);
private:
    static long maxId;

};

#endif // GRAPH_H
