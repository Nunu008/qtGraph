#ifndef DIALOG_H
#define DIALOG_H

#include <QDebug>
#include <QDialog>
#include <QtGui>
#include <QtCore>
#include <QGraphicsScene>
#include <QStandardItemModel>
#include <QStandardItem>


#include "graph.h"
#include "node.h"

namespace Ui {
class Dialog;
}

class Graph;

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

    void test1();
    void test2();
    void test3();
    void test4();
    void test5();
    void test6();
    void test7();
    void test8();
    void test9();
    void test10();

private:
    Ui::Dialog *ui;


public:
    static QGraphicsScene     *scene;
    static QStandardItemModel *qhashModel;

    Graph *graph;

protected:
    virtual void wheelEvent(QWheelEvent* event);

};

#endif // DIALOG_H
