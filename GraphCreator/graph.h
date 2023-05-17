#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

#include "types.h"

using namespace std;

class Graph
{
private:
    vector<Node *> nodes;

public:
    ~Graph();
    bool add(Node *);
    bool remove(char *);
    Node *find(char *);
};

#endif // GRAPH_H