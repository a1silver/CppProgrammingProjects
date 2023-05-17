#include <cstring>
#include <iostream>
#include <vector>

#include "graph.h"
#include "types.h"

using namespace std;

Graph::Graph()
{
    this->nodeCount = 0;
}

Graph::~Graph()
{
    vector<Node *>::iterator it;
    for (it = this->nodes.begin(); it != this->nodes.end(); it++)
    {
        delete *it;
    }
    this->nodes.clear();
    // todo
}

bool Graph::add(Node *node)
{
    Node *found = this->find(node->label);
    if (found != nullptr)
        return false;
    this->nodes.push_back(node);
    this->nodeCount++;
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
            this->nodeCount--;
            return true;
        }
    }
    return false;
}

bool Graph::removeConnection(Node *first, Node *second)
{
    bool removed = false;
    // We have to iterate through the connections for both nodes, as the connection could start at either one
    vector<Edge *>::iterator it1;
    for (it1 = first->connections.begin(); it1 != first->connections.end(); it1++)
    {
        if ((*it1)->end == second)
        {
            delete *it1;
            first->connections.erase(it1);
            removed = true;
            break;
        }
    }
    vector<Edge *>::iterator it2;
    for (it2 = second->connections.begin(); it2 != second->connections.end(); it2++)
    {
        if ((*it2)->end == first)
        {
            delete *it2;
            second->connections.erase(it2);
            removed = true;
            break;
        }
    }
    return removed;
}

Node *Graph::find(char *label)
{
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

void Graph::listNodes()
{
    vector<Node *>::iterator it;
    for (it = this->nodes.begin(); it != this->nodes.end(); it++)
    {
        cout << (*it)->label << endl;
    }
}

void Graph::printAdjacencyMatrix()
{
    // Create the adjacency matrix
    vector<vector<bool>> adjacencyMatrix(this->nodeCount, vector<bool>(this->nodeCount)); // Create a vector of this->nodeCount bool vectors (each size this->nodeCount)
    for (int i = 0; i < this->nodeCount; i++)
    {
        for (int j = 0; j < this->nodeCount; j++)
        {
            Node *first = this->nodes[i];
            Node *second = this->nodes[j];
            bool connected = false;
            if (first->isConnectedTo(second))
            {
                connected = true;
            }
            adjacencyMatrix[i][j] = connected;
        }
    }

    for (int j = -1; j < this->nodeCount; j++)
    {
        for (int i = -1; i < this->nodeCount; i++)
        {
            if (j == -1 & i == -1)
            {
                cout << "   ";
                continue;
            }

            if (j == -1)
            {
                int len = strlen(this->nodes[i]->label);
                int spacesCount = 3 - len;
                if (len == 1)
                {
                    cout << " " << this->nodes[i]->label << " ";
                } else {
                    cout << this->nodes[i]->label << " ";
                }
                continue;
            }

            if (i == -1)
            {
                int len = strlen(this->nodes[j]->label);
                int spacesCount = 3 - len;
                cout << this->nodes[j]->label;
                for (int i = 0; i < spacesCount; i++)
                {
                    cout << " ";
                }
                continue;
            }

            cout << " " << (adjacencyMatrix[i][j] ? "X" : "O") << " ";
        }
        cout << endl;
    }
}