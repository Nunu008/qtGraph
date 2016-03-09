#include "mainwindow.h"
#include "ui_mainwindow.h"

QGraphicsScene* MainWindow::scene = NULL;
QStandardItemModel *MainWindow::qhashModel = NULL;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    qhashModel = new QStandardItemModel(this);

    qhashModel->setColumnCount(2);
    qhashModel->setRowCount(12);

    QStringList header;
    header<< "ID"<<"Node label";
    qhashModel->setHorizontalHeaderLabels(header);


    graph = new Graph();

    //test1();
    //test2();
    //test3();
    //test4();
    //test5();
    //test6();
    //test7();
    //test8();
    //test9();
    //test10();
    //test11();
    test12();

    int i=0;
    QHashIterator<int,Node*> Iter(graph->getNodes());
    while(Iter.hasNext())
    {
        Iter.next();
        qDebug()<<Iter.key() <<" : " << Iter.value()->getLabel();
        qhashModel->setData(qhashModel->index(i, 0),Iter.key());
        qhashModel->setData(qhashModel->index(i, 1),Iter.value()->getLabel());
        i++;
    }



    ui->treeView->setModel(qhashModel);
    ui->graphicsView->setScene(scene);
    ui->treeView->resizeColumnToContents(0);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::wheelEvent(QWheelEvent *event){

        ui->graphicsView->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
        // Scale the view / do the zoom
        double scaleFactor = 1.15;
        if(event->delta() > 0) {
            // Zoom in
            ui->graphicsView-> scale(scaleFactor, scaleFactor);

        } else {
            // Zooming out
             ui->graphicsView->scale(1.0 / scaleFactor, 1.0 / scaleFactor);
        }

}

void MainWindow::test1()
{

    Node *start = graph->createNode("s");
    Node *end   = graph->createNode("e");

    graph->createEdge(start,"test1",end);

    start->ellipse->refreshEdges();
    end->ellipse->refreshEdges();

}


void MainWindow::test2()
{

    Node *start  = graph->createNode("s");
    Node *middel = graph->createNode("m");
    Node *end    = graph->createNode("e");
    Node *x      = graph->createNode("x");

    graph->createEdge(start, "test",middel);
    //graph->createEdge(middel,"test",start);

    graph->createEdge(middel,"test",end);
    //graph->createEdge(end,   "test",middel);

    graph->createEdge(middel,"test",x);

    start->ellipse->refreshEdges();
    middel->ellipse->refreshEdges();
    end->ellipse->refreshEdges();
    x->ellipse->refreshEdges();
}



void MainWindow::test3()
{

    Node *start  = graph->createNode("s");
    Node *middel = graph->createNode("m");
    graph->createEdge(start, "test", middel);

    QList<Node*> nodeList;

    nodeList.append(start);
    nodeList.append(middel);


    for(int i = 1; i< 10 ; i++)
    {
      Node *newNode = graph->createNode("x");
      graph->createEdge(newNode,"x",nodeList.last());
      nodeList.append(newNode);
      newNode->ellipse->refreshEdges();
    }

    graph->createEdge(nodeList.last(),"",nodeList.first());

    nodeList.first()->ellipse->refreshEdges();
    nodeList.last()->ellipse->refreshEdges();
}



void MainWindow::test4()
{


    Node *x1 = graph->createNode("x1");
    Node *y1 = graph->createNode("y1");
    Node *y2 = graph->createNode("y2");
    Node *y3 = graph->createNode("y3");

    graph->createEdge(x1,"x1_To_y1",y1);
    graph->createEdge(y1,"y1_To_x1",x1);

    graph->createEdge(x1,"x1_To_y2",y2);
    graph->createEdge(y2,"y2_To_x1",x1);

    graph->createEdge(x1,"x1_To_y3",y3);
    graph->createEdge(y3,"y3_To_x1",x1);



    x1->ellipse->refreshEdges();
    y1->ellipse->refreshEdges();
    y2->ellipse->refreshEdges();
    y3->ellipse->refreshEdges();
}



void MainWindow::test5()
{



    Node *m1       = graph->createNode("missionar");

    Node *leftBank = graph->createNode("bank");

    leftBank->setNodeAttribute("side","left");


    graph->createEdge(m1,"at", leftBank);


    m1->ellipse->refreshEdges();
    leftBank->ellipse->refreshEdges();


}


void MainWindow::test6()
{
    //start graph

    Node *leftBank = graph->createNode("l");
    Node *rightBank= graph->createNode("r");

    leftBank->setNodeAttribute("side","left");
    rightBank->setNodeAttribute("side","right");


    Node *boat = graph->createNode("boat");

    graph->createEdge(boat,"at", leftBank);


    Node *m1       = graph->createNode("m1");
    Node *m2       = graph->createNode("m2");
    Node *m3       = graph->createNode("m3");

    graph->createEdge(m1,"at", leftBank);
    graph->createEdge(m2,"at", leftBank);
    graph->createEdge(m3,"at", leftBank);


    Node *c1       = graph->createNode("c1");
    Node *c2       = graph->createNode("c2");
    Node *c3       = graph->createNode("c3");

    graph->createEdge(c1,"at", leftBank);
    graph->createEdge(c2,"at", leftBank);
    graph->createEdge(c3,"at", leftBank);



    leftBank->ellipse->refreshEdges();
    rightBank->ellipse->refreshEdges();

    boat->ellipse->refreshEdges();

    m1->ellipse->refreshEdges();
    m2->ellipse->refreshEdges();
    m3->ellipse->refreshEdges();

    c1->ellipse->refreshEdges();
    c2->ellipse->refreshEdges();
    c3->ellipse->refreshEdges();
}




void MainWindow::test7()
{

    //first graph
    Node *start = graph->createNode("s");
    Node *end   = graph->createNode("e");

    graph->createEdge(start,"test1",end);

    start->ellipse->refreshEdges();
    end->ellipse->refreshEdges();

    //clone graph

    Graph *g2 = graph->clone();
}


void MainWindow::test8()
{

    Node *start  = graph->createNode("s");
    Node *middel = graph->createNode("m");
    graph->createEdge(start, "test", middel);

    QList<Node*> nodeList;

    nodeList.append(start);
    nodeList.append(middel);


    for(int i = 1; i< 10 ; i++)
    {
      Node *newNode = graph->createNode("x");
      graph->createEdge(newNode,"x",nodeList.last());
      nodeList.append(newNode);
      newNode->ellipse->refreshEdges();
    }

    graph->createEdge(nodeList.last(),"",nodeList.first());

    nodeList.first()->ellipse->refreshEdges();
    nodeList.last()->ellipse->refreshEdges();


    //clone graph

    Graph *g2 = graph->clone();

}

void MainWindow::test9()
{


    Node *start = graph->createNode("s");
    Node *end   = graph->createNode("e");

    graph->createEdge(start,"test1",end);

    start->ellipse->refreshEdges();
    end->ellipse->refreshEdges();

    //clone graph
    Graph *g2 = graph->clone();

    //Graph *overallGraph = new Graph();


}

void MainWindow::test10()
{

    Node *start  = graph->createNode("s");
    Node *middel = graph->createNode("m");
    Node *end    = graph->createNode("e");
    Node *x      = graph->createNode("x");

    graph->createEdge(start, "test",middel);
    //graph->createEdge(middel,"test",start);

    graph->createEdge(middel,"test",end);
    //graph->createEdge(end,   "test",middel);

    graph->createEdge(middel,"test",x);

    start->ellipse->refreshEdges();
    middel->ellipse->refreshEdges();
    end->ellipse->refreshEdges();
    x->ellipse->refreshEdges();


    graph->removeEdge( middel, "test", x);
}



void MainWindow::test11()
{
    //draw Graph
      Node *start  = graph->createNode("s");
      Node *end    = graph->createNode("e");

      graph->createEdge(start, "test",end);

      start->ellipse->refreshEdges();
      end->ellipse->refreshEdges();

}

void MainWindow::test12()
{
    //start graph

    Node *leftBank = graph->createNode("l");
    Node *rightBank= graph->createNode("r");

    leftBank->setNodeAttribute("side","left");
    rightBank->setNodeAttribute("side","right");


    Node *boat = graph->createNode("boat");

    graph->createEdge(boat,"at", leftBank);


    Node *m1       = graph->createNode("m1");
    Node *m2       = graph->createNode("m2");
    Node *m3       = graph->createNode("m3");

    graph->createEdge(m1,"at", leftBank);
    graph->createEdge(m2,"at", leftBank);
    graph->createEdge(m3,"at", leftBank);


    Node *c1       = graph->createNode("c1");
    Node *c2       = graph->createNode("c2");
    Node *c3       = graph->createNode("c3");

    graph->createEdge(c1,"at", leftBank);
    graph->createEdge(c2,"at", leftBank);
    graph->createEdge(c3,"at", leftBank);



    leftBank->ellipse->refreshEdges();
    rightBank->ellipse->refreshEdges();

    boat->ellipse->refreshEdges();

    m1->ellipse->refreshEdges();
    m2->ellipse->refreshEdges();
    m3->ellipse->refreshEdges();

    c1->ellipse->refreshEdges();
    c2->ellipse->refreshEdges();
    c3->ellipse->refreshEdges();



    //clone graph
    Graph *g2 = graph->clone();

}
