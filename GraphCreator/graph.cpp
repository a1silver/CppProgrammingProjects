#include <cstring>
#include <vector>

#include "graph.h"
#include "types.h"

using namespace std;

Graph::~Graph()
{
    vector<Node *>::iterator it;
    for(it = this->nodes.begin(); it != this->nodes.end(); it++)
    {
        delete *it;
    }
    this->nodes.clear();
    // todo
}

bool Graph::add(Node *node)
{
    Node *found = this->find(node->label);
    if (found != nullptr) return false;
    this->nodes.push_back(node);
    return true;
}

bool Graph::remove(char *label)
{
    vector<Node *>::iterator it;
    for (it = this->nodes.begin(); it != this->nodes.end(); it++)
    {
        if (strcmp((*it)->label, label) == 0)
        {
            delete *it;
            this->nodes.erase(it);
            return true;
        }
    }
    return false;
}

Node *Graph::find(char *label) {
    vector<Node *>::iterator it;
    for (it = this->nodes.begin(); it != this->nodes.end(); it++)
    {
        if (strcmp((*it)->label, label) == 0)
        {
            return *it;
        }
    }
    return nullptr;
}