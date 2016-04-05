#ifndef RULE_H
#define RULE_H

#include "graph.h"

class Graph;

class Rule
{
public:
    Rule();


    Graph *getLeftGraph() const;
    void setLeftGraph(Graph *value);

    Graph *getRightGraph() const;
    void setRightGraph(Graph *value);

private:
    Graph *leftGraph;
    Graph *rightGraph;


};

#endif // RULE_H
