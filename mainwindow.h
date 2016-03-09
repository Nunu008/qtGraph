#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QMainWindow>
#include <QtGui>
#include <QtCore>
#include <QGraphicsScene>
#include <QStandardItemModel>
#include <QStandardItem>


#include "graph.h"
#include "node.h"

namespace Ui {
class MainWindow;
}


class Graph;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

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
    void test11();
    void test12();


private:
    Ui::MainWindow *ui;

public:
    static QGraphicsScene     *scene;
    static QStandardItemModel *qhashModel;

    Graph *graph;


protected:
    virtual void wheelEvent(QWheelEvent* event);


};

#endif // MAINWINDOW_H
