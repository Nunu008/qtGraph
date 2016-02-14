#ifndef NODE_H
#define NODE_H

#include <QGraphicsItem>
#include <QGraphicsEllipseItem>
#include <QHash>
#include <QMap>

#include "nodeset.h"
#include "customitem.h"

class NodeSet;

class Node
{
public:
    Node();
    void setEllipseIsMoveable();
    void setEllipseIsSelectable();

public:
    //QGraphicsEllipseItem *ellipse;
    customItem *ellipse;



    long getId() const;
    void setId(const long &value);

    void createEdge(QString label, Node tgt);
private:
    long id;
    QMap<QString, NodeSet> neighbors;


};

#endif // NODE_H
