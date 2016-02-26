#include "graph.h"


long Graph::maxId = 0;

Graph::Graph()
{

}

NodeSet Graph::getNodes()
{
    return nodes;
}

Node* Graph::createNode(QString label)
{
    /*
    //logic elements
    Node newNode;

    newNode.setId(maxId+1);
    nodes.insert(maxId+1,newNode);
    maxId++;
    newNode.setLabel(label);


    //gui elements
    newNode.ellipse = new CustomItem();
    newNode.ellipse->mName = label;
    Dialog::scene->addItem(newNode.ellipse);
    */

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


    return newNode;
}

void Graph::createEdge(Node *src, const QString & label, Node *tgt)
{
    //logic elements
    //src.createEdge(label, tgt);
    src->createEdge(label, tgt);

    //Gui elments
    /*
    src.ellipse->customLine = new  QGraphicsLineItem(0,0,0,0);
    Dialog::scene->addItem(src.ellipse->customLine);
    src.ellipse->setLine(src.ellipse->customLine,false);// for false create enum with start and end
    tgt.ellipse->setLine(src.ellipse->customLine,true);
    */

    src->ellipse->customLine = new  QGraphicsLineItem(0,0,0,0);
    Dialog::scene->addItem(src->ellipse->customLine);
    src->ellipse->setLine(src->ellipse->customLine,false);// for false create enum with start and end
    tgt->ellipse->setLine(src->ellipse->customLine,true);
}

Graph* Graph::clone()
{
  /*
    Graph *result = new Graph();

   //QHash<Node,Node> *cloneMap = new QHash<Node,Node>();
    QMap<Node,Node> cloneMap;
    Node oldNode;

   // loop over all nodes
   QHashIterator<int,Node> Iter(this->getNodes());
   while(Iter.hasNext())
   {
       Iter.next();
       // create clone nodes
       Node newNodeClone = result->createNode(Iter.value().getLabel() );
       // copy attributes
       QHashIterator<QString,QString> Iter2(Iter.value().getNodeAttribute());
       while(Iter2.hasNext())
       {
           Iter2.next();
           newNodeClone.setNodeAttribute(Iter2.key(),Iter2.value());
       }

       //cloneMap->insert(Iter.value(),newNodeClone);

       oldNode= Iter.value();
       //cloneMap.insert( oldNode, newNodeClone);

   }

   // loop over all nodes
   while(Iter.hasNext())
   {
       //Node srcClone = cloneMap[Iter.value()];

       // loop over neighbours of node to create edges
       QHashIterator<QString,NodeSet> Iter3(Iter.value().getNeighbours());
       while(Iter3.hasNext())
       {
           Iter3.next();
           if(!Iter3.key().startsWith("_rev_"))
           {
            NodeSet neighbourSet = Iter3.value();

            QHashIterator<int,Node> Iter4(neighbourSet);
            while(Iter4.hasNext())
            {
                Iter4.next();
            }
           }
       }
   }

    return result;
    */
}
