#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#include <climits>

#include "graph.h"
#include "types.h"

#define reset "\033[0m"
#define green "\033[32m"

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

bool Graph::isFull()
{
    return this->nodeCount == 20;
}

bool Graph::isEmpty()
{
    return this->nodeCount == 0;
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
    // Find the correct node in the list
    vector<Node *>::iterator foundNode;
    for (foundNode = this->nodes.begin(); foundNode != this->nodes.end(); foundNode++)
    {
        // We found the correct node
        if (strcmp((*foundNode)->label, label) == 0)
        {
            // Iterate through all connections that are part of our found node
            vector<Edge *>::iterator connection;
            for (connection = (*foundNode)->connections.begin(); connection != (*foundNode)->connections.end(); connection++)
            {
                Node *end = (*connection)->end;

                this->removeConnection(*foundNode, end);
                break;
            }
            delete *foundNode;
            this->nodes.erase(foundNode);
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

            if (j == -1) // Printing the top row of node labels
            {
                int len = strlen(this->nodes[i]->label);
                int spacesCount = 3 - len;
                if (len == 1)
                {
                    cout << " " << this->nodes[i]->label << " ";
                }
                else
                {
                    cout << this->nodes[i]->label << " ";
                }
                continue;
            }

            if (i == -1) // Printing the side column of node labels
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

            if (adjacencyMatrix[i][j])
            {
                cout << " " << green << "X" << reset << " ";
            }
            else
            {
                cout << " O ";
            }
        }
        cout << endl;
    }
}

int Graph::indexOf(Node *node)
{
    vector<Node *>::iterator it;
    for (it = this->nodes.begin(); it != this->nodes.end(); it++)
    {
        if (strcmp((*it)->label, node->label) == 0)
        {
            return it - this->nodes.begin();
        }
    }
    return -1;
}

int Graph::indexOf(char *label)
{
    vector<Node *>::iterator it;
    for (it = this->nodes.begin(); it != this->nodes.end(); it++)
    {
        if (strcmp((*it)->label, label) == 0)
        {
            return it - this->nodes.begin();
        }
    }
    return -1;
}

Edge *Graph::getShortestConnector(Node *node)
{
    Edge *connector = nullptr;
    float shortest = INT_MAX;
    vector<Edge *>::iterator it;
    for (it = node->connections.begin(); it != node->connections.end(); it++)
    {
        if ((*it)->weight < shortest)
        {
            connector = *it;
            shortest = connector->weight;
        }
    }
    return connector;
}

int Graph::minDistanceIndex(vector<float> distances, vector<bool> visited)
{
    float minimum = INT_MAX;
    int index;

    for (int i = 0; i < this->nodeCount; i++)
    {
        if (!visited[i] && distances[i] < minimum)
        {
            minimum = distances[i];
            index = i;
        }
    }

    return index;
}

int randomFunction(vector<char *> previousNodes, char *label)
{
    vector<char *>::iterator it;
    for (it = previousNodes.begin(); it != previousNodes.end(); it++)
    {
        if (strcmp(*it, label) == 0)
        {
            return it - previousNodes.begin();
        }
    }
    return -1;
}

void Graph::printShortestPath(Node *start, Node *end)
{
    vector<float> distances;
    vector<bool> visited;
    vector<char *> previousNodes;

    for (int i = 0; i < this->nodeCount; i++)
    {
        distances.push_back(INT_MAX);
        visited.push_back(false);
        char lmao[1];
        strcpy(lmao, "");
        previousNodes.push_back(lmao);
    }

    int startIndex = this->indexOf(start);
    int endIndex = this->indexOf(end);

    distances[startIndex] = 0.0f;

    for (int i = 0; i < this->nodeCount; i++)
    {
        int idx = this->minDistanceIndex(distances, visited);
        visited[idx] = true;

        for (int j = 0; j < this->nodeCount; j++)
        {
            if (!visited[j] &&
                this->nodes[idx]->isConnectedTo(this->nodes[j]) &&
                distances[idx] + this->nodes[idx]->getConnectionTo(this->nodes[j])->weight < distances[j])
            {
                if (j == 0)
                {
                    char lmao[1];
                    strcpy(lmao, "");
                    previousNodes[j] = lmao;
                }
                else
                {
                    previousNodes[j] = this->nodes[idx]->label;
                }
                distances[j] = distances[idx] + this->nodes[idx]->getConnectionTo(this->nodes[j])->weight;
            }
        }
    }

    Node *current = end;

    vector<char *> path;

    while (true)
    {
        int currentIndex = this->indexOf(current);
        float distance = distances[currentIndex];
        if (distance == INT_MAX)
        {
            cout << "No valid path found between nodes \"" << start->label << "\" and \"" << end->label << "\"" << endl;
            return;
        }
        path.push_back(current->label);
        char *previousLabel = previousNodes[currentIndex];
        if (strcmp(previousLabel, "") == 0)
        {
            break;
        }
        int previousIndexOf = this->indexOf(previousLabel);
        current = this->nodes[previousIndexOf];
    }

    vector<char *>::reverse_iterator it;
    for (it = path.rbegin(); it != path.rend(); it++)
    {
        cout << (*it) << " -> ";
    }
    cout << "END" << endl;
    cout << "Path length: " << distances[endIndex] << endl;
    
    /*
    while (true)
    {
        int currentIndex = this->indexOf(current);
        char *previousLabel = previousNodes[currentIndex];
        int previousIndex = randomFunction(previousNodes, previousLabel);

        if (strcmp(start->label, previousLabel) == 0) // current == start || strcmp(previousLabel, "") == 0
        {
            path.push_back(previousLabel);
            break;
        }
        if (previousIndex == -1)
        {
            cout << "No valid path found between \"" << start->label << "\" and \"" << end->label << "\"." << endl;
            return;
        }
        path.push_back(previousLabel);
        current = this->nodes[previousIndex];
    }

    vector<char *>::iterator it;
    for (it = path.begin(); it != path.end(); it++)
    {
        cout << (*it) << " -> ";
    }
    cout << "END" << endl;
    cout << "Path length: " << distances[endIndex] << endl;
    */
}

void Graph::printAllPaths(Node *start)
{
    vector<float> distances;
    vector<bool> visited;
    vector<char *> previousNodes;

    for (int i = 0; i < this->nodeCount; i++)
    {
        distances.push_back(INT_MAX);
        visited.push_back(false);
        char lmao[1];
        strcpy(lmao, "");
        previousNodes.push_back(lmao);
    }

    int startIndex = this->indexOf(start);

    distances[startIndex] = 0.0f;

    for (int i = 0; i < this->nodeCount; i++)
    {
        int idx = this->minDistanceIndex(distances, visited);
        visited[idx] = true;

        for (int j = 0; j < this->nodeCount; j++)
        {
            if (!visited[j] &&
                this->nodes[idx]->isConnectedTo(this->nodes[j]) &&
                distances[idx] + this->nodes[idx]->getConnectionTo(this->nodes[j])->weight < distances[j])
            {
                if (j == 0)
                {
                    char lmao[1];
                    strcpy(lmao, "");
                    previousNodes[j] = lmao;
                }
                else
                {
                    previousNodes[j] = this->nodes[idx]->label;
                }
                distances[j] = distances[idx] + this->nodes[idx]->getConnectionTo(this->nodes[j])->weight;
            }
        }
    }

    cout << "Vertex\t\tDistance from source vertex\t\tPrevious node" << endl;
    for (int i = 0; i < this->nodeCount; i++)
    {
        if (distances[i] == INT_MAX)
        {
            cout << this->nodes[i]->label << "      \t\tNO PATH                           " << previousNodes[i] << endl;
        }
        else
        {
            cout << this->nodes[i]->label << "      \t\t" << distances[i] << "                           " << previousNodes[i] << endl;
        }
    }
}