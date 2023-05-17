#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

#include "types.h"

using namespace std;

class Graph
{
private:
    vector<Node *> nodes;
    int nodeCount;

public:
    Graph();
    ~Graph();
    bool add(Node *);
    bool remove(char *);
    bool removeConnection(Node *, Node *);
    Node *find(char *);
    void listNodes();
    void printAdjacencyMatrix();
};

#endif // GRAPH_H