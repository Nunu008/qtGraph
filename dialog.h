#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsItem>



#include "node.h"
#include "nodeset.h"


namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

    Node createNode(QString name,long newId);

    void createEdge(Node src, QString label, Node tgt);
    void refreshNodesEdges();

    void test1();
    void test2();
    void test3();

private:
    Ui::Dialog *ui;

    QGraphicsScene *scene;

    static long maxIdNode;

    NodeSet nodes;

    Node node;
};

#endif // DIALOG_H
