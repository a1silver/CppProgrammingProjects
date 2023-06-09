#include <vector>

#include "types.h"

using namespace std;

// Returns true of the found connection to the provided other node is not null
bool Node::isConnectedTo(Node *otherNode)
{
    return this->getConnectionTo(otherNode) != nullptr;
}

// Get the Edge object for a connection between the current node and the provided other node
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