#include "dialog.h"
#include "ui_dialog.h"

QGraphicsScene* Dialog::scene = NULL;

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    test1();
    test2();
    //test3();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::test1()
{
    Graph graph;

    Node start = graph.createNode("s",0);
    Node end   = graph.createNode("e",0);

    graph.createEdge(start,"test",end);
    graph.createEdge(end,  "test",start);

    start.ellipse->refreshEdges();
    end.ellipse->refreshEdges();
}


void Dialog::test2()
{
    Graph graph;

    Node start = graph.createNode("s",0);
    Node middel = graph.createNode("m",0);
    Node end   = graph.createNode("e",0);

    graph.createEdge(start, "test",middel);
    graph.createEdge(middel,"test",start);

    graph.createEdge(middel,"test",end);
    graph.createEdge(end,   "test",middel);

    start.ellipse->refreshEdges();
    middel.ellipse->refreshEdges();
    end.ellipse->refreshEdges();
}


void Dialog::test3()
{
    Graph graph;

    Node start  = graph.createNode("s",0);
    Node middel = graph.createNode("m",0);
    graph.createEdge(start, "test", middel);

    QList<Node> nodeList;

    nodeList.append(start);
    nodeList.append(middel);


    for(int i = 1; i< 10 ; i++)
    {
      Node newNode = graph.createNode("",0);
      graph.createEdge(newNode,"",nodeList.last());
      nodeList.append(newNode);
      newNode.ellipse->refreshEdges();
    }

    graph.createEdge(nodeList.last(),"",nodeList.first());

    nodeList.first().ellipse->refreshEdges();
    nodeList.last().ellipse->refreshEdges();
}
