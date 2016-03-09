#ifndef RULE_H
#define RULE_H

#include "graph.h"

class Rule
{
public:
    Rule();

    Graph getRightGraph() const;
    void setRightGraph(const Graph &value);

    Graph getLeftGraph() const;
    void setLeftGraph(const Graph &value);

private:
    Graph leftGraph;
    Graph rightGraph;
};

#endif // RULE_H
