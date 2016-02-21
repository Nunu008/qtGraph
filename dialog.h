#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QGraphicsScene>

#include "graph.h"

namespace Ui {
class Dialog;
}

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
private:
    Ui::Dialog *ui;

public:
    static QGraphicsScene *scene;


};

#endif // DIALOG_H
