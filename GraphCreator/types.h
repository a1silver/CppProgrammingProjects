#ifndef TYPES_H
#define TYPES_H

#include <vector>

using namespace std;

struct Node; // Forward declarations

struct Edge {
    Node *end;
    float weight;
};

struct Node
{
    char label[51];
    vector<Edge> connections;
    bool isConnectedTo(Node *);
};

#endif // TYPES_H