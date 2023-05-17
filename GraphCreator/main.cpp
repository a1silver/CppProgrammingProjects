#include <iostream>
#include <cstring>

#include "graph.h"
#include "types.h"

using namespace std;

// Commands
const char ADD_CMD[] = "ADD";
const char REMOVE_CMD[] = "REMOVE";
const char OPT_NODE[] = "NODE";
const char OPT_EDGE[] = "EDGE";
const char CLEAR_CMD[] = "CLEAR";
const char ADJMAT_CMD[] = "ADJMAT"; // Adjacency matrix
const char SHORTEST_CMD[] = "SHORTEST";
const char QUIT_CMD[] = "QUIT";
const char EXIT_CMD[] = "EXIT";

int main()
{
    Graph *graph = new Graph();

    cout << "Directional Graph Creator by Morgan Hinz" << endl;

    while (true)
    {
        cout << "ADD, REMOVE, CLEAR, ADJMAT, SHORTEST, or QUIT | EXIT" << endl;
        cout << "----------------------------------------------------" << endl;
        char cmd[9];
        cin >> cmd;

        if (strcmp(cmd, ADD_CMD) == 0)
        {
            cout << "NODE or EDGE: ";
            char opt[5];
            cin >> opt;

            if (strcmp(opt, OPT_NODE) == 0)
            {
                Node *newNode = new Node();
                cout << "Enter up to 50 characters for the node label: ";
                cin.ignore();
                cin.getline(newNode->label, 50, '\n');
                if (!graph->add(newNode))
                {
                    cout << "A node with the label \"" << newNode->label << "\" already exists." << endl;
                    delete newNode;
                }
                else
                {
                    cout << "Added node \"" << newNode->label << "\"" << endl;
                }
            }
            if (strcmp(opt, OPT_EDGE) == 0)
            {
                Edge edge;
                cout << "Enter the label of the first node (up to 50 characters): ";
                char label1[51];
                cin.ignore();
                cin.getline(label1, 50, '\n');
                cout << "Enter the label of the second node (up to 50 characters): ";
                char label2[51];
                cin.getline(label2, 50, '\n');
                cout << "Enter the weight of the edge (floating point numbers are acceptable): ";
                cin >> edge.weight;

                if (strcmp(label1, label2) == 0)
                {
                    cout << "Both labels can't be the same." << endl;
                    continue;
                }

                Node *first = graph->find(label1);
                Node *second = graph->find(label2);
                if (first == nullptr)
                {
                    cout << "A node with the label \"" << label1 << "\" wasn't found." << endl;
                    continue;
                }
                if (second == nullptr)
                {
                    cout << "A node with the label \"" << label2 << "\" wasn't found." << endl;
                    continue;
                }
                if (strcmp(first->label, second->label) == 0) // This shouldn't ever happen
                {
                    cout << "Both labels can't be the same." << endl;
                    continue;
                }
                if (first->isConnectedTo(second))
                {
                    cout << "The node \"" << first->label << "\" already has a connection to \"" << second->label << "\"." << endl;
                    continue;
                }
                if (second->isConnectedTo(first))
                {
                    cout << "The node \"" << second->label << "\" already has a connection to \"" << first->label << "\"." << endl;
                    continue;
                }

                edge.end = second;

                first->connections.push_back(edge);
                cout << "Added an edge with weight " << edge.weight << " between nodes \"" << first->label << "\" and \"" << second->label << "\"." << endl;
            }
        }
        if (strcmp(cmd, REMOVE_CMD) == 0)
        {
            cout << "NODE or EDGE: ";
            char opt[5];
            cin >> opt;

            if (strcmp(opt, OPT_NODE) == 0)
            {
                cout << "Enter the label of a node to remove (up to 50 characters): ";
                char lb[51];
                cin.ignore();
                cin.getline(lb, 50, '\n');
                if (!graph->remove(lb))
                {
                    cout << "A node with the label \"" << lb << "\" could not be found." << endl;
                }
                else
                {
                    cout << "Removed the node \"" << lb << "\" from the graph." << endl;
                }
            }
            if (strcmp(opt, OPT_EDGE) == 0)
            {
                
            }
        }
        if (strcmp(cmd, CLEAR_CMD) == 0)
        {
            delete graph;
            graph = new Graph();
            cout << "Cleared the graph." << endl;
        }
        if (strcmp(cmd, ADJMAT_CMD) == 0)
        {
        }
        if (strcmp(cmd, SHORTEST_CMD) == 0)
        {
        }
        if (strcmp(cmd, QUIT_CMD) == 0 || strcmp(cmd, EXIT_CMD) == 0)
        {
            break;
        }
        cout << endl;
    }

    delete graph;

    return 0;
}