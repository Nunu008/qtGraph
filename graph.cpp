#include "graph.h"


long Graph::maxId = 0;

Graph::Graph()
{
    this->ellipse = new CustomItem();
    this->ellipse->setGraph();
    this->ellipse->setScale(5);
    Dialog::scene->addItem(this->ellipse);

    //group = Dialog::scene->createItemGroup(Dialog::scene->selectedItems ());
    //group->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable);
    //group->addToGroup(this->ellipse);
}

NodeSet Graph::getNodes()
{
    return nodes;
}

Node* Graph::createNode(QString label)
{


    //logic elements
    Node *newNode = new  Node();
    newNode->setId(maxId+1);
    nodes.insert(maxId+1,newNode);
    maxId++;
    newNode->setLabel(label);

    //
    newNode->ellipse = new CustomItem();
    newNode->ellipse->mName = label;

    Dialog::scene->addItem(newNode->ellipse);
    //group->addToGroup(newNode->ellipse);
    return newNode;
}

void Graph::createEdge(Node *src, const QString & label, Node *tgt)
{
    //logic elements
    src->createEdge(label, tgt);

    //Gui elments
    src->ellipse->customLine = new  QGraphicsLineItem(0,0,0,0);

    Dialog::scene->addItem(src->ellipse->customLine);
    //group->addToGroup(src->ellipse->customLine);
    src->ellipse->setLine(src->ellipse->customLine,false);// for false create enum with start and end
    tgt->ellipse->setLine(src->ellipse->customLine,true);
    src->ellipse->setNeighbours(src->neighbours);
    tgt->ellipse->setNeighbours(tgt->neighbours);
}

void Graph::removeEdge(Node *src, const QString & label, Node *tgt)
{
    //logic elements
    src->removeEdge(label, tgt);


    //Gui elments
    Dialog::scene->removeItem(src->ellipse->customLine);
    src->ellipse->setNeighbours(src->neighbours);
    tgt->ellipse->setNeighbours(tgt->neighbours);
}

Graph* Graph::clone()
{

    Graph *result = new Graph();

   //QHash<Node,Node> *cloneMap = new QHash<Node,Node>();
    QMap<Node*,Node*> cloneMap;
    Node *oldNode;

   // loop over all nodes
   QHashIterator<int,Node*> Iter(this->getNodes());
   while(Iter.hasNext())
   {
       Iter.next();
       // create clone nodes
       Node *newNodeClone = result->createNode(Iter.value()->getLabel() );
       // copy attributes
       QHashIterator<QString,QString> Iter2(Iter.value()->getNodeAttribute());
       while(Iter2.hasNext())
       {
           Iter2.next();
           newNodeClone->setNodeAttribute(Iter2.key(),Iter2.value());
       }

       //cloneMap->insert(Iter.value(),newNodeClone);

       oldNode= Iter.value();
       cloneMap.insert( oldNode, newNodeClone);

   }

   // loop over all nodes
   QHashIterator<int,Node*> Iter5(this->getNodes());
   while(Iter5.hasNext())
   {
       Iter5.next();
       Node *srcClone = cloneMap[Iter5.value()];

       // loop over neighbours of node to create edges
       QHashIterator<QString,NodeSet> Iter3(Iter5.value()->getNeighbours());
       while(Iter3.hasNext())
       {
           Iter3.next();
           if(!Iter3.key().startsWith("_rev_"))
           {
            NodeSet neighbourSet = Iter3.value();

            QHashIterator<int,Node*> Iter4(neighbourSet);
            while(Iter4.hasNext())
            {
                Iter4.next();
                Node *tgtClone = cloneMap[Iter4.value()];
                this->createEdge(srcClone,Iter3.key(),tgtClone);
                srcClone->ellipse->refreshEdges();
                tgtClone->ellipse->refreshEdges();
            }
           }
       }
   }

    return result;

}
