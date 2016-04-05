#ifndef NODE_H
#define NODE_H

#include <QHash>
#include <QString>
#include <QStandardItemModel>
#include <QDebug>

#include "nodeset.h"
#include "customitem.h"

class NodeSet;
class CustomItem;

class Node
{
public:
    Node();
    ~Node();
    void setId(const long &value);
    long getId();

    void createEdge(const QString & label, Node *tgt);
    void removeEdge(const QString &label, Node *tgt);

    void setLabel(QString label);
    QString getLabel() const;


    QHash<QString, NodeSet> getNeighbours() const;
    NodeSet  getNeighbours(QString label);
    void setNodeAttribute(QString attrName, QString value);

    QHash<QString, QString> attributes;

private:
    long id;




public:
    QString label;
    CustomItem *ellipse;
    QHash<QString,NodeSet> neighbours;
    QHash<QString,QString> nodeAttribute;

    QHash<QString,QString> getNodeAttribute()const;
    QString getNodeAttribute(QString attrName) const;


};

#endif // NODE_H
