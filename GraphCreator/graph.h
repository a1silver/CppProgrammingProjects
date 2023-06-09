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
    Edge *getShortestConnector(Node *);
    int minDistanceIndex(vector<float>, vector<bool>);

public:
    Graph();
    ~Graph();
    bool isFull();
    bool isEmpty();
    bool add(Node *);
    bool remove(char *);
    bool removeConnection(Node *, Node *);
    Node *find(char *);
    void listNodes();
    void printAdjacencyMatrix();
    void printShortestPath(Node *, Node *);
    void printAllPaths(Node *);
    int indexOf(Node *);
    int indexOf(char *);
};

#endif // GRAPH_H