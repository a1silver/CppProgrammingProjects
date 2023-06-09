#include <iostream>
#include <cstring>

#include "graph.h"
#include "types.h"

using namespace std;

// Commands
const char ADD_CMD[] = "add";
const char REMOVE_CMD[] = "remove";
const char OPT_NODE[] = "node";
const char OPT_EDGE[] = "edge";
const char CLEAR_CMD[] = "clear";
const char LIST_CMD[] = "list";     // Show all nodes
const char ADJMAT_CMD[] = "adjmat"; // Adjacency matrix
const char SHORTEST_CMD[] = "shortest";
const char OPT_ALL[] = "all";
const char OPT_SINGLE[] = "single";
const char QUIT_CMD[] = "quit";
const char EXIT_CMD[] = "exit";

int main()
{
    Graph *graph = new Graph();

    cout << "Directional Graph Creator by Morgan Hinz" << endl;

    // Get user commands
    while (true)
    {
        cout << "ADD, REMOVE, CLEAR, LIST, ADJMAT, SHORTEST, or QUIT | EXIT" << endl;
        cout << "----------------------------------------------------------" << endl;
        cout << " > ";
        char cmd[9];
        cin >> cmd;

        // This for loop takes care of ignoring any case sensitivity
        for (int i = 0; i < strlen(cmd); i++)
        {
            cmd[i] = tolower(cmd[i]);
        }

        if (strcmp(cmd, ADD_CMD) == 0)
        {
            cout << "NODE or EDGE: ";
            char opt[5];
            cin >> opt;

            // This for loop takes care of ignoring any case sensitivity
            for (int i = 0; i < strlen(opt); i++)
            {
                opt[i] = tolower(opt[i]);
            }

            if (strcmp(opt, OPT_NODE) == 0)
            {
                if (graph->isFull())
                {
                    cout << "There can be no more than 20 nodes in the graph." << endl;
                    continue;
                }
                Node *newNode = new Node();
                cout << "Enter up to 2 characters for the node label: ";
                char label[2];
                for (int i = 0; i < 2; i++)
                {
                    label[i] = '\0';
                }
                cin >> label;
                strncpy(newNode->label, label, 2); // If you don't do this, the new node will get a label that's longer than 2 characters

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
                Edge *edge = new Edge();
                cout << "Enter the label of the first node (up to 2 characters): ";
                char label1[3];
                cin >> label1;
                cout << "Enter the label of the second node (up to 2 characters): ";
                char label2[3];
                cin >> label2;
                cout << "Enter the weight of the edge (floating point numbers are acceptable): ";
                cin >> edge->weight;

                if (strcmp(label1, label2) == 0)
                {
                    cout << "Both labels can't be the same." << endl
                         << endl;
                    continue;
                }

                Node *first = graph->find(label1);
                Node *second = graph->find(label2);
                if (first == nullptr)
                {
                    cout << "A node with the label \"" << label1 << "\" wasn't found." << endl
                         << endl;
                    continue;
                }
                if (second == nullptr)
                {
                    cout << "A node with the label \"" << label2 << "\" wasn't found." << endl
                         << endl;
                    continue;
                }
                if (strcmp(first->label, second->label) == 0) // This shouldn't ever happen
                {
                    cout << "Both labels can't be the same." << endl
                         << endl;
                    continue;
                }
                Edge *firstToSecond = first->getConnectionTo(second);
                Edge *secondToFirst = second->getConnectionTo(first);
                if (firstToSecond != nullptr)
                {
                    cout << "The node \"" << first->label << "\" (a) already has a connection to \"" << second->label << "\" (b)   (a->b)." << endl
                         << endl;
                    continue;
                }
                if (secondToFirst != nullptr)
                {
                    cout << "The node \"" << second->label << "\" (a) already has a connection to \"" << first->label << "\" (b)   (b->a)." << endl
                         << endl;
                    continue;
                }

                edge->start = first;
                edge->end = second;

                first->connections.push_back(edge);
                cout << "Added an edge with weight " << edge->weight << " between nodes \"" << first->label << "\" and \"" << second->label << "\"." << endl;
            }
        }
        if (strcmp(cmd, REMOVE_CMD) == 0)
        {
            cout << "NODE or EDGE: ";
            char opt[5];
            cin >> opt;

            // This for loop takes care of ignoring any case sensitivity
            for (int i = 0; i < strlen(opt); i++)
            {
                opt[i] = tolower(opt[i]);
            }

            if (strcmp(opt, OPT_NODE) == 0)
            {
                cout << "Enter the label of a node to remove (up to 2 characters): ";
                char lb[2];
                cin >> lb;
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
                cout << "Enter the label of the first node (up to 2 characters): ";
                char label1[2];
                cin >> label1;
                cout << "Enter the label of the second node (up to 2 characters): ";
                char label2[2];
                cin >> label2;

                if (strcmp(label1, label2) == 0)
                {
                    cout << "Both labels can't be the same." << endl
                         << endl;
                    continue;
                }

                Node *first = graph->find(label1);
                Node *second = graph->find(label2);
                if (first == nullptr)
                {
                    cout << "A node with the label \"" << label1 << "\" wasn't found." << endl
                         << endl;
                    continue;
                }
                if (second == nullptr)
                {
                    cout << "A node with the label \"" << label2 << "\" wasn't found." << endl
                         << endl;
                    continue;
                }
                if (strcmp(first->label, second->label) == 0) // This shouldn't ever happen
                {
                    cout << "Both labels can't be the same." << endl
                         << endl;
                    continue;
                }
                Edge *firstToSecond = first->getConnectionTo(second);
                Edge *secondToFirst = second->getConnectionTo(first);
                if (firstToSecond == nullptr)
                {
                    if (secondToFirst == nullptr)
                    {
                        if (firstToSecond == nullptr)
                        {
                            cout << "The node \"" << first->label << "\" doesn't have a connection to \"" << second->label << "\"." << endl
                                 << endl;
                            continue;
                        }
                        else
                        {
                            cout << "The node \"" << second->label << "\" doesn't have a connection to \"" << first->label << "\"." << endl
                                 << endl;
                            continue;
                        }
                    }
                }

                if (!graph->removeConnection(first, second)) // This should never happen, but it's good to be sure
                {
                    cout << "Removal of the edge failed." << endl;
                }
                else
                {
                    cout << "The edge between " << first->label << " and " << second->label << " has been deleted." << endl;
                }
            }
        }
        if (strcmp(cmd, CLEAR_CMD) == 0)
        {
            delete graph;
            graph = new Graph();
            cout << "Cleared the graph." << endl;
        }
        if (strcmp(cmd, LIST_CMD) == 0)
        {
            graph->listNodes();
        }
        if (strcmp(cmd, ADJMAT_CMD) == 0)
        {
            graph->printAdjacencyMatrix();
        }
        if (strcmp(cmd, SHORTEST_CMD) == 0)
        {
            cout << "ALL or SINGLE: ";
            char opt[7];
            cin >> opt;

            if (strcmp(opt, OPT_ALL) == 0)
            {
                cout << "Enter the label of the first node (up to 2 characters): ";
                char label1[2];
                cin >> label1;

                Node *first = graph->find(label1);
                if (first == nullptr)
                {
                    cout << "A node with the label \"" << label1 << "\" wasn't found." << endl
                         << endl;
                    continue;
                }
                graph->printAllPaths(first);
            }
            if (strcmp(opt, OPT_SINGLE) == 0)
            {
                cout << "Enter the label of the first node (up to 2 characters): ";
                char label1[2];
                cin >> label1;
                cout << "Enter the label of the second node (up to 2 characters): ";
                char label2[2];
                cin >> label2;

                if (strcmp(label1, label2) == 0)
                {
                    cout << "Both labels can't be the same." << endl
                         << endl;
                    continue;
                }

                Node *first = graph->find(label1);
                Node *second = graph->find(label2);
                if (first == nullptr)
                {
                    cout << "A node with the label \"" << label1 << "\" wasn't found." << endl
                         << endl;
                    continue;
                }
                if (second == nullptr)
                {
                    cout << "A node with the label \"" << label2 << "\" wasn't found." << endl
                         << endl;
                    continue;
                }
                if (strcmp(first->label, second->label) == 0) // This shouldn't ever happen
                {
                    cout << "Both labels can't be the same." << endl
                         << endl;
                    continue;
                }

                graph->printShortestPath(first, second);
            }
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