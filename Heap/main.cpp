#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <time.h>

#include "heap.h"

using namespace std;

const char ADD_CMD[] = "add";
const char ADD_OPT_MANUAL[] = "manual";
const char ADD_OPT_FILE[] = "file";
const char ADD_MANUAL_FLAG_DONE_UC[] = "DONE";
const char ADD_MANUAL_FLAG_DONE_LC[] = "done";
const char REMOVE_CMD[] = "remove";
const char REMOVE_OPT_MAX[] = "max";
const char REMOVE_OPT_ALL[] = "all";
const char DISPLAY_CMD[] = "display";
const char DEBUG_CMD[] = "debug";
const char DEBUG_CMD_MAX[] = "max";
const char DEBUG_CMD_PEEK[] = "peek";
const char DEBUG_CMD_PEEK_YES[] = "yes";
const char DEBUG_CMD_PEEK_NO[] = "no";
const char DEBUG_CMD_QUIT[] = "quit";
const char DEBUG_CMD_EXIT[] = "exit";
const char HELP_CMD[] = "help";
const char QUIT_CMD[] = "quit";
const char EXIT_CMD[] = "exit";

int main()
{
    Heap *heap = new Heap(100);

    cout << "C++ Data Structures (Max Heap)" << endl;
    cout << "Morgan Hinz, Period 8" << endl;
    cout << "Type \"HELP\" at any time for a list of commands." << endl;

    char cmd[8];

    while (true)
    {
        cout << "_______________________________________________________" << endl
             << endl;
        cout << "> ";
        cin >> cmd;

        // This for loop takes care of ignoring any case sensitivity
        for (int i = 0; i < strlen(cmd); i++)
        {
            cmd[i] = tolower(cmd[i]);
        }

        if (strcmp(cmd, ADD_CMD) == 0)
        {
            if (heap->isHeapFull())
            {
                cout << "Heap is full, you can't add any more numbers." << endl;
            }
            else
            {
                cout << "How would you like to add numbers?" << endl;
                cout << "Type either \"MANUAL\" or \"FILE\"." << endl;
                cout << "ADD > ";

                char opt[7];
                cin >> opt;

                // This for loop takes care of ignoring any case sensitivity
                for (int i = 0; i < strlen(opt); i++)
                {
                    opt[i] = tolower(opt[i]);
                }

                if (strcmp(opt, ADD_OPT_MANUAL) == 0)
                {
                    cout << "Enter space-separated integers to add to the heap. Type \"DONE\" when finished." << endl;

                    char input[17];
                    char count = 0;
                    int skipped = 0;
                    while (true)
                    {
                        if (heap->isHeapFull())
                        {
                            cout << "Heap is full, you can't add any more numbers." << endl;
                            break;
                        }
                        cin >> input;
                        if (strcmp(input, ADD_MANUAL_FLAG_DONE_UC) == 0 || strcmp(input, ADD_MANUAL_FLAG_DONE_LC) == 0)
                        {
                            break;
                        }
                        int value;
                        sscanf(input, "%d", &value);
                        if (value <= 0 || value > 1000)
                        {
                            skipped++;
                        }
                        else
                        {
                            heap->insert(value);
                        }
                        count++;
                    }
                    if (skipped > 0)
                    {
                        cout << "Warning: " << skipped << " numbers were skipped.  Make sure your numbers are between 1 and 1000, inclusive." << endl;
                    }
                    cout << "Added " << (count - skipped) << " numbers." << endl;
                }
                if (strcmp(opt, ADD_OPT_FILE) == 0)
                {
                    cout << "Reading in numbers... ";
                    vector<int> numbers;
                    int numberCount = 0;

                    ifstream numbersFile("numbers.txt");
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
                    }
                    cout << "done." << endl;

                    cout << numberCount << " numbers were found.  How many do you want to add? ";
                    int amount;
                    cin >> amount;
                    if (amount < 0)
                    {
                        cout << "Canceled." << endl;
                    }
                    else
                    {
                        if (amount > numberCount)
                        {
                            amount = numberCount;
                        }

                        int skipped = 0;

                        for (int i = 0; i < amount; i++)
                        {
                            if (heap->isHeapFull())
                            {
                                cout << "Heap is full, you can't add any more numbers." << endl;
                                amount = i;
                                break;
                            }

                            if (numbers[i] <= 0 || numbers[i] > 1000)
                            {
                                skipped++;
                            }
                            else
                            {
                                heap->insert(numbers[i]);
                            }
                        }

                        cout << "Added " << (amount - skipped) << " numbers." << endl;
                    }
                }
            }
        }
        if (strcmp(cmd, REMOVE_CMD) == 0)
        {
            cout << "Type \"MAX\" to remove only the max number, \"ALL\" to remove everything." << endl;
            cout << "REMOVE > ";

            char opt[8];
            cin >> opt;

            if (strcmp(opt, REMOVE_OPT_MAX) == 0)
            {
                int oldSize = heap->getHeapSize();
                int oldMax = heap->extractMax();
                int nwSize = heap->getHeapSize();
                int nwMax = heap->getMax();
                cout << "Max value extracted." << endl;
                cout << "Old max value: " << oldMax << "   Old size: " << oldSize << endl;
                if (nwSize > 0)
                {
                    cout << "New max value: " << nwMax << "   New size: " << nwSize << endl;
                }
                else
                {
                    cout << "New heap size is zero, no new max value exists." << endl;
                }
            }
            if (strcmp(opt, REMOVE_OPT_ALL) == 0)
            {
                int size = heap->getHeapSize();
                cout << "Extracted numbers:" << endl;
                while (heap->getHeapSize() != 0)
                {
                    cout << heap->extractMax() << " ";
                }
                cout << endl;
                cout << size << " numbers were removed from the heap." << endl;
            }
        }
        if (strcmp(cmd, DISPLAY_CMD) == 0)
        {
            heap->printHeap(0, 0);
        }
        if (strcmp(cmd, DEBUG_CMD) == 0)
        {
            while (true)
            {
                cout << "DEBUG > ";

                char debugcmd[8];
                cin >> debugcmd;

                if (strcmp(debugcmd, DEBUG_CMD_MAX) == 0)
                {
                    cout << "Max value: " << heap->getMax() << endl;
                }
                if (strcmp(debugcmd, DEBUG_CMD_PEEK) == 0)
                {
                    cout << "Peek at what index? ";
                    int idx;
                    cin >> idx;

                    if (idx > heap->getHeapSize() - 1)
                    {
                        cout << "Index is larger than heap size, display anyway? ";
                        char ans[4];
                        cin >> ans;

                        if (strcmp(ans, DEBUG_CMD_PEEK_YES) == 0)
                        {
                            cout << "Peeking at index: " << idx << endl;
                            cout << "Found value: " << heap->peek(idx) << endl;
                        }
                        else
                        {
                            cout << "Skipping." << endl;
                        }
                    }
                    else
                    {
                        cout << "Peeking at index: " << idx << endl;
                        cout << "Found value: " << heap->peek(idx) << endl;
                    }
                }
                if (strcmp(debugcmd, DEBUG_CMD_QUIT) == 0 || strcmp(debugcmd, DEBUG_CMD_EXIT) == 0)
                {
                    break;
                }
                cout << endl;
            }
        }
        if (strcmp(cmd, HELP_CMD) == 0)
        {
            cout << "List of commands:" << endl;
            cout << "\t - add - Add numbers to the heap." << endl;
            cout << "\t\t - manual - Add numbers (space separated) to the heap.  Type \"DONE\" when done." << endl;
            cout << "\t\t - file - Add numbers to the heap from a file (numbers.txt)" << endl;
            cout << "\t - remove - Remove numbers from the heap." << endl;
            cout << "\t\t - max - Only remove the maximum value from the heap." << endl;
            cout << "\t\t - all - Remove everything from the heap." << endl;
            cout << "\t - display - Display the heap in a nice tree showing the parent-child relationships of all nodes." << endl;
            cout << "\t - debug - Enter debug mode." << endl;
            cout << "\t\t - max - Print the maximum value to the console." << endl;
            cout << "\t\t - peek - Get the value from any index in the heap." << endl;
            cout << "\t\t - quit | exit - Exit the program." << endl;
            cout << "\t - quit | exit - Exit the program." << endl;
        }
        if (strcmp(cmd, QUIT_CMD) == 0 || strcmp(cmd, EXIT_CMD) == 0)
        {
            delete heap;
            break;
        }
    }

    return 0;
}