#include "rule.h"

Rule::Rule()
{

}

Graph *Rule::getLeftGraph() const
{
    return leftGraph;
}

void Rule::setLeftGraph(Graph *value)
{
    leftGraph = value;
}

Graph *Rule::getRightGraph() const
{
    return rightGraph;
}

void Rule::setRightGraph(Graph *value)
{
    rightGraph = value;
}

