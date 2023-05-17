#include <vector>

#include "types.h"

using namespace std;

bool Node::isConnectedTo(Node *otherNode)
{
    vector<Edge>::iterator it;
    for (it = this->connections.begin(); it != this->connections.end(); it++)
    {
        if ((*it).end == otherNode)
        {
            return true;
        }
    }
    return false;
}