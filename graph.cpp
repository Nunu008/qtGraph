#include "graph.h"

long Graph::maxIdNodeGraph  = 0;

Graph::Graph()
{

}

Node Graph::createNode(QString name, long newId)
{

    Node newNode;

    newNode.setId(maxIdNodeGraph+1);

    nodes.insert(maxIdNodeGraph+1,newNode);

    maxIdNodeGraph++;

    qsrand(qrand());


    newNode.ellipse = new customItem();
    newNode.ellipse->mName = name;

    scene->addItem(newNode.ellipse);

    return newNode;
}

void Graph::createEdge(Node src, QString label, Node tgt)
{
    src.createEdge(label, tgt);

    src.ellipse->customLine = new  QGraphicsLineItem(0,0,0,0);
    scene->addItem(src.ellipse->customLine);


    src.ellipse->setLine(src.ellipse->customLine,false);// for false create enum with start and end
    tgt.ellipse->setLine(src.ellipse->customLine,true);

}


void Graph::refreshNodesEdges()
{
    QHashIterator<int,Node> Iter(nodes);

    while(Iter.hasNext())
    {
        Iter.next();
        qDebug() << Iter.key();
        Iter.value().ellipse->refreshEdges();

    }
}


void Graph::test1()
{
    Node start  = createNode("start",0);
    Node end    = createNode("end",0);

    createEdge(start, "test", end);

}

void Graph::test2()
{
    Node start  = createNode("start",0);
    Node middel= createNode("middel",0);
    Node end    = createNode("end",0);

    createEdge(start,  "test", middel);
    createEdge(middel, "test", end);

    start.ellipse->refreshEdges();
    middel.ellipse->refreshEdges();
    end.ellipse->refreshEdges();


}

void Graph::test3()
{
    Node start  = createNode("start",0);
    Node middel= createNode("middel",0);
    createEdge(start, "test", middel);

    QList<Node> nodeList;

    nodeList.append(start);
    nodeList.append(middel);


    for(int i = 1; i< 10 ; i++)
    {
      Node newNode = createNode("",0);
      createEdge(newNode,"",nodeList.last());
      nodeList.append(newNode);
    }

    createEdge(nodeList.last(),"",nodeList.first());

}
