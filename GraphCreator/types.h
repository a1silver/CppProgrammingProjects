#ifndef TYPES_H
#define TYPES_H

#include <vector>

using namespace std;

// Forward declarations
struct Node;

struct Edge
{
    Node *start;
    Node *end;
    float weight;
};

struct Node
{
    char label[3];
    vector<Edge *> connections;
    bool isConnectedTo(Node *);
    Edge *getConnectionTo(Node *);
};

#endif // TYPES_H

/*
    This header file contains the definition for the Edge and Node structs.

    The Edge struct defines an edge, or a connection, between two nodes.  It also holds a specified weight; this weight is important data used in Djikstra's algorithm.

    The Node struct defines a graph node.  It has a label (2 characters maximum) and a list of connections (Edge objects).
*/