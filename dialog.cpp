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

    createNode(0);
    createNode(0);

    //createEdge();


}

Dialog::~Dialog()
{
    delete ui;
}

Node Dialog::createNode(long newId)
{

    Node newNode;

    newNode.setId(maxIdNode+1);

    nodes.insert(maxIdNode+1,newNode);

    maxIdNode++;


//    QBrush whiteBrush(Qt::white);
//    QPen   outlinePen(Qt::gray);
//    outlinePen.setWidth(5);

    qsrand(qrand());

    //newNode.ellipse = scene->addEllipse(0, -100, 50, 50, outlinePen, whiteBrush);
//    newNode.ellipse = scene->addEllipse(qrand() % ((High + 1) - Low) + Low,
//                                        qrand() % ((High + 1) - Low) + Low, 50, 50, outlinePen, whiteBrush);
//    newNode.setEllipseIsMoveable();
//    newNode.setEllipseIsSelectable();

    newNode.ellipse = new customItem();

    scene->addItem(newNode.ellipse);

    return newNode;
}

void Dialog::createEdge(Node src, QString label, Node tgt)
{
    src.ellipse->customLine = new  QGraphicsLineItem(0,0,0,0);
    scene->addItem(src.ellipse->customLine);

    src.createEdge(label, tgt);

}
