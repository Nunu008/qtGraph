#include "dialog.h"
#include "ui_dialog.h"


#define High -200
#define Low  200

long Dialog::maxIdNode = 0;

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);


    //test1();
    test2();

}

Dialog::~Dialog()
{
    delete ui;
}

Node Dialog::createNode(QString name, long newId)
{

    Node newNode;

    newNode.setId(maxIdNode+1);

    nodes.insert(maxIdNode+1,newNode);

    maxIdNode++;

    qsrand(qrand());


    newNode.ellipse = new customItem();
    newNode.ellipse->mName = name;

    scene->addItem(newNode.ellipse);

    return newNode;
}

void Dialog::createEdge(Node src, QString label, Node tgt)
{
    src.createEdge(label, tgt);

    src.ellipse->customLine = new  QGraphicsLineItem(0,0,0,0);
    scene->addItem(src.ellipse->customLine);


    src.ellipse->setLine(src.ellipse->customLine,false);// for false create enum with start and end
    tgt.ellipse->setLine(src.ellipse->customLine,true);

}

void Dialog::test1()
{
    Node start  = createNode("start",0);
    Node end    = createNode("end",0);

    createEdge(start, "test", end);

}

void Dialog::test2()
{
    Node start  = createNode("start",0);
    Node middel= createNode("middel",0);
    Node end    = createNode("end",0);

    createEdge(start, "test", end);
    createEdge(start, "test", middel);

}
