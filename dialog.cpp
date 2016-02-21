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

    //test1();
    //test2();
    //test3();
    test4();
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

void Dialog::test4()
{
    Graph graph;

    Node x1 = graph.createNode("x1",0);
    Node y1 = graph.createNode("y1",0);
    Node y2 = graph.createNode("y2",0);
    Node y3 = graph.createNode("y3",0);

    graph.createEdge(x1,"x1_To_y1",y1);
    graph.createEdge(y1,"y1_To_x1",x1);

    graph.createEdge(x1,"x1_To_y2",y2);
    graph.createEdge(y2,"y2_To_x1",x1);

    graph.createEdge(x1,"x1_To_y3",y3);
    graph.createEdge(y3,"y3_To_x1",x1);



    x1.ellipse->refreshEdges();
    y1.ellipse->refreshEdges();
    y2.ellipse->refreshEdges();
    y3.ellipse->refreshEdges();
}
