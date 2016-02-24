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
    long getId();

    void createEdge(const QString & label, Node & tgt);

    void setLabel(QString label);

    NodeSet getNeighbours(QString label);

private:
    long id;


    QString label;

public:
    CustomItem *ellipse;
    QHash<QString,NodeSet> neighbours;
    QHash<QString,QString> nodeAttribute;


    QString getNodeAttribute(QString attrName);
    void setNodeAttribute(QString attrName, QString value);
};

#endif // NODE_H
