#include "rule.h"

Rule::Rule()
{

}

Graph Rule::getRightGraph() const
{
    return rightGraph;
}

void Rule::setRightGraph(const Graph &value)
{
    rightGraph = value;
}

Graph Rule::getLeftGraph() const
{
    return leftGraph;
}

void Rule::setLeftGraph(const Graph &value)
{
    leftGraph = value;
}

