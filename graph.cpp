#include "graph.h"


long Graph::maxId= 0;

Graph::Graph()
{

}

Node Graph::createNode(QString name, long newId)
{
    Node newNode;

    newNode.setId(maxId+1);
    nodes.insert(maxId+1,newNode);
    maxId++;

    newNode.ellipse = new CustomItem();
    newNode.ellipse->mName = name;


    Dialog::scene->addItem(newNode.ellipse);


    return newNode;
}

void Graph::createEdge(Node src, QString label, Node tgt)
{
    src.createEdge(label, tgt);

    src.ellipse->customLine = new  QGraphicsLineItem(0,0,0,0);

    Dialog::scene->addItem(src.ellipse->customLine);


    src.ellipse->setLine(src.ellipse->customLine,false);// for false create enum with start and end
    tgt.ellipse->setLine(src.ellipse->customLine,true);

}
