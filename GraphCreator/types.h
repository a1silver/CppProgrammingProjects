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