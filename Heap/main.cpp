#include <iostream>
#include <cstdio>
#include <cstring>

#include "heap.h"

using namespace std;

const char ADD_CMD[] = "add";
const char ADD_OPT_MANUAL[] = "manual";
const char ADD_OPT_FILE[] = "file";
const char ADD_MANUAL_FLAG_DONE_UC[] = "DONE";
const char ADD_MANUAL_FLAG_DONE_LC[] = "done";
const char REMOVE_CMD[] = "remove";
const char REMOVE_OPT_LARGEST[] = "largest";
const char REMOVE_OPT_ALL[] = "all";
const char DISPLAY_CMD[] = "display";
const char QUIT_CMD[] = "quit";
const char EXIT_CMD[] = "exit";

int main()
{
    Heap *heap = new Heap(100);

    cout << "C++ Data Structures (Max Heap)" << endl;
    cout << "Morgan Hinz, Period 8" << endl;

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
            cout << "How would you like to add numbers?" << endl;
            cout << "Type either \"MANUAL\" or \"FILE\"." << endl;
            cout << " > ";

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
                    cout << value << endl;
                    heap->insert(value);
                    count++;
                }
                cout << "Added " << count << " numbers." << endl;
            }
            if (strcmp(opt, ADD_OPT_FILE) == 0)
            {
                
            }
        }
        if (strcmp(cmd, REMOVE_CMD) == 0)
        {
        }
        if (strcmp(cmd, DISPLAY_CMD) == 0)
        {
            heap->printHeap(heap->getHeapSize(), 0, 0);
        }
        if (strcmp(cmd, QUIT_CMD) == 0 || strcmp(cmd, EXIT_CMD) == 0)
        {
            delete heap;
            break;
        }
    }

    return 0;
}