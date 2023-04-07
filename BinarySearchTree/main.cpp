// C++ program to demonstrate insertion
// in a BST recursively.
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <fstream>

#include "node.h"
#include "bst.h"
using namespace std;

const char ADD_CMD[] = "ADD";
const char ADD_OPT_MANUAL[] = "MANUAL";
const char ADD_MANUAL_FLAG_DONE[] = "DONE";
const char ADD_OPT_FILE[] = "FILE";
const char REMOVE_CMD[] = "REMOVE";
const char SEARCH_CMD[] = "SEARCH";
const char DISPLAY_CMD[] = "DISPLAY";
const char QUIT_CMD[] = "QUIT";
const char EXIT_CMD[] = "EXIT";

int main()
{
    BST *b = new BST();

    cout << "Binary Search Tree by Morgan Hinz" << endl;

    while (true)
    {
        cout << "--------------------------------------------" << endl;
        cout << "ADD, REMOVE, SEARCH, DISPLAY, or QUIT | EXIT" << endl;
        cout << " > ";
        char cmd[8];
        cin >> cmd;

        if (strcmp(cmd, ADD_CMD) == 0)
        {
            cout << "MANUAL or FILE" << endl;
            cout << " > ";
            char opt[7];
            cin >> opt;

            if (strcmp(opt, ADD_OPT_MANUAL) == 0)
            {
                cout << "Enter space-separated integers to add to the heap. Type \"DONE\" when finished." << endl;

                char input[17];
                char count = 0;
                int skipped = 0;
                while (true)
                {
                    cin >> input;
                    if (strcmp(input, ADD_MANUAL_FLAG_DONE) == 0)
                    {
                        break;
                    }
                    int value;
                    sscanf(input, "%d", &value);
                    if (value <= 0 || value > 999)
                    {
                        skipped++;
                    }
                    else
                    {
                        b->add(value);
                    }
                    count++;
                }
                if (skipped > 0)
                {
                    cout << "Warning: " << skipped << " numbers were skipped.  Make sure your numbers are between 1 and 1000, exclusive." << endl;
                }
                cout << "Added " << (count - skipped) << " numbers." << endl;
            }
            if (strcmp(opt, ADD_OPT_FILE) == 0)
            {
                cout << " Enter file name > ";
                char filename[261];
                cin >> filename;
                cout << "Reading in numbers... ";
                vector<int> numbers;
                int numberCount = 0;

                ifstream numbersFile(filename);
                if (numbersFile.is_open())
                {
                    int val;
                    while (!numbersFile.eof())
                    {
                        numbersFile >> val;
                        numbers.push_back(val);
                        numberCount++;
                    }
                    numbersFile.close();

                    int skipped = 0;
                    for (int i = 0; i < numberCount; i++)
                    {
                        if (numbers[i] <= 0 || numbers[i] > 1000)
                        {
                            skipped++;
                        }
                        else
                        {
                            b->add(numbers[i]);
                        }
                    }

                    if (skipped > 0)
                    {
                        cout << "Warning: " << skipped << " numbers were skipped.  Make sure your numbers are between 1 and 1000, exclusive." << endl;
                    }
                    cout << "Added " << (numberCount - skipped) << " numbers." << endl;
                } else {
                    cout << "Failed to open file: " << filename << endl;
                }
            }
        }
        if (strcmp(cmd, REMOVE_CMD) == 0)
        {
            cout << " Enter value to remove > ";
            int number;
            cin >> number;
            b->remove(number);
        }
        if (strcmp(cmd, SEARCH_CMD) == 0)
        {
            cout << " Enter value to search for > ";
            int number;
            cin >> number;
            if (b->search(number))
            {
                cout << "Found " << number << " in the tree." << endl;
            }
            else
            {
                cout << "Did not find " << number << " in the tree." << endl;
            }
        }
        if (strcmp(cmd, DISPLAY_CMD) == 0)
        {
            b->display();
        }
        if (strcmp(cmd, QUIT_CMD) == 0 || strcmp(cmd, EXIT_CMD) == 0)
        {
            break;
        }
    }

    delete b;
    return 0;
}
