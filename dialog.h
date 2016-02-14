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

    Node createNode(long newId);

    void createEdge(Node src, QString label, Node tgt);

private:
    Ui::Dialog *ui;

    QGraphicsScene *scene;

    static long maxIdNode;

    NodeSet nodes;

    Node node;
};

#endif // DIALOG_H
