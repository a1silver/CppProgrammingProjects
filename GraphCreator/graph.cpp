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
        vector<Edge *>::iterator it1;
        for (it1 = (*it)->connections.begin(); it1 != (*it)->connections.end(); it1++)
        {
            delete *it1;
        }
        (*it)->connections.clear();
        delete *it;
    }
    this->nodes.clear();
    // todo
}

// Returns true if the nodeCount is equal to 20
bool Graph::isFull()
{
    return this->nodeCount == 20;
}

// Returns true if the nodeCount is equal to zero
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

// Remove a node with the given label from the graph
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

// Remove a connection between two nodes in the graph.  This does not remove the nodes.
bool Graph::removeConnection(Node *first, Node *second)
{
    bool removed = false;
    // We have to iterate through the connections for both nodes, as the connection could start at either one

    // Iterate through the connections for the first node...
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

    // And then interate through the connections for the second node
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

// Find a node with the given label
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

// List all nodes in the graph and their connections.
void Graph::listNodes()
{
    vector<Node *>::iterator it;
    for (it = this->nodes.begin(); it != this->nodes.end(); it++)
    {
        cout << (*it)->label << "   Connections: ";
        vector<Edge *>::iterator it1;
        for (it1 = (*it)->connections.begin(); it1 != (*it)->connections.end(); it1++)
        {
            cout << (*it1)->end->label << endl;
        }
        cout << endl;
    }
}

/*
    Print out the adjacency matrix.
    An adjacency matrix shows which nodes are connected to which nodes.
    ---
    A sample adjacency matrix could be the following:

      A B C D E
    A 0 0 0 0 0
    B X 0 0 0 0
    C 0 X 0 0 0
    D X X 0 0 0
    E X 0 X 0 0

    ---
    An X indicates that two nodes are connected to each other.
    An O indicates that two nodes are not connected to each other (imagine the O as an empty space).
    In this adjacency matrix, nodes on the top row are connected to nodes on the side column.
    For example, the X at (B, C) means that the node with a label of "B" is connected to the node with a label of "C".
*/
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

// Get the index of a node that matches the label of the given node
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

// Get the index of a node that matches the given label
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

// Get the index of the smallest unvisited node
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

/*
    Use Djikstra's algorithm to find the shortest path from one node to another.

    This function finds the same information as Graph::printAllPaths, but it will then use said information find a single shortest path.
*/
void Graph::printShortestPath(Node *start, Node *end)
{
    // Vectors for recording information generated by Djikstra's algorithm
    vector<float> distances;
    vector<bool> visited;
    vector<char *> previousNodes;

    // Prepare the vectors
    for (int i = 0; i < this->nodeCount; i++)
    {
        distances.push_back(INT_MAX); // Distances start at infinity (they're unknown)
        visited.push_back(false);     // Set all nodes to not visited
        char lmao[1];
        strcpy(lmao, "");
        previousNodes.push_back(lmao); // Set all of the previous nodes to nothing
    }

    int startIndex = this->indexOf(start);
    int endIndex = this->indexOf(end);

    distances[startIndex] = 0.0f; // The distance from a node to the same node should be 0...

    // We have to do this process for every node
    for (int i = 0; i < this->nodeCount; i++)
    {
        int idx = this->minDistanceIndex(distances, visited); // Get the index of the smallest unvisited node
        visited[idx] = true;                                  // We've visited this node

        // Iterate through all nodes again because we have to update shortest distances and previous nodes for each node in the list
        for (int j = 0; j < this->nodeCount; j++)
        {
            /*
                If the node "j" isn't visited,
                the node "i" is connected to the node "j",
                and the current minimum node added to the current node's connection's weight is smaller than the actual distance between nodes "i" and "j"
            */
            if (!visited[j] &&
                this->nodes[idx]->isConnectedTo(this->nodes[j]) &&
                distances[idx] + this->nodes[idx]->getConnectionTo(this->nodes[j])->weight < distances[j])
            {
                // Update previous nodes
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
                // Update shortest distances
                distances[j] = distances[idx] + this->nodes[idx]->getConnectionTo(this->nodes[j])->weight;
            }
        }
    }

    Node *current = end;
    vector<char *> path;

    // Keep searching for a shortest path until we hit a distance of inifinity or our current node doesn't have a previous node
    while (true)
    {
        int currentIndex = this->indexOf(current);
        float distance = distances[currentIndex];
        if (distance == INT_MAX) // The distance is infinity, so that means there's no connection between our current node and its previous node
        {
            cout << "No valid path found between nodes \"" << start->label << "\" and \"" << end->label << "\"" << endl;
            return;
        }
        path.push_back(current->label); // Add the current node to the path vector
        char *previousLabel = previousNodes[currentIndex];
        if (strcmp(previousLabel, "") == 0) // If the label of the current node's previous node is nonexistent, we've reached the end of the path!
        {
            break;
        }
        // Update the current node to be the current node's previous node
        int previousIndexOf = this->indexOf(previousLabel);
        current = this->nodes[previousIndexOf];
    }

    // Print out the path in reverse, as nodes are added starting at the end of the path
    vector<char *>::reverse_iterator it;
    for (it = path.rbegin(); it != path.rend(); it++)
    {
        cout << (*it) << " -> ";
    }
    cout << "END" << endl;

    // Print out the final path length
    cout << "Path length: " << distances[endIndex] << endl;
}

// Use Djikstra's algorithm to find the shortest path to each node from a given starting node
void Graph::printAllPaths(Node *start)
{
    // Vectors for recording information generated by Djikstra's algorithm
    vector<float> distances;
    vector<bool> visited;
    vector<char *> previousNodes;

    // Prepare the vectors
    for (int i = 0; i < this->nodeCount; i++)
    {
        distances.push_back(INT_MAX); // Distances start at infinity (they're unknown)
        visited.push_back(false);     // Set all nodes to not visited
        char lmao[1];
        strcpy(lmao, "");
        previousNodes.push_back(lmao); // Set all of the previous nodes to nothing
    }

    int startIndex = this->indexOf(start);

    distances[startIndex] = 0.0f; // The distance from a node to the same node should be 0...

    // We have to do this process for every node
    for (int i = 0; i < this->nodeCount; i++)
    {
        int idx = this->minDistanceIndex(distances, visited); // Get the index of the smallest unvisited node
        visited[idx] = true;                                  // We've visited this node

        // Iterate through all nodes again because we have to update shortest distances and previous nodes for each node in the list
        for (int j = 0; j < this->nodeCount; j++)
        {
            /*
                If the node "j" isn't visited,
                the node "i" is connected to the node "j",
                and the current minimum node added to the current node's connection's weight is smaller than the actual distance between nodes "i" and "j"
            */
            if (!visited[j] &&
                this->nodes[idx]->isConnectedTo(this->nodes[j]) &&
                distances[idx] + this->nodes[idx]->getConnectionTo(this->nodes[j])->weight < distances[j])
            {
                // Update previous nodes
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
                // Update shortest distances
                distances[j] = distances[idx] + this->nodes[idx]->getConnectionTo(this->nodes[j])->weight;
            }
        }
    }

    // Print out all paths in a neat table
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