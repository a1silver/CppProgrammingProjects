#include <vector>

#include "types.h"

using namespace std;

bool Node::isConnectedTo(Node *otherNode)
{
    return this->getConnectionTo(otherNode) != nullptr;
}

Edge *Node::getConnectionTo(Node *otherNode)
{
    vector<Edge *>::iterator it;
    for (it = this->connections.begin(); it != this->connections.end(); it++)
    {
        if ((*it)->end == otherNode)
        {
            return *it;
        }
    }
    return nullptr;
}