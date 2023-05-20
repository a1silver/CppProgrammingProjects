#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>

#include "rbt.h"
#include "node.h"

using namespace std;

// Commands
const char ADD_CMD[] = "ADD";
const char ADD_OPT_MANUAL[] = "MANUAL";
const char ADD_MANUAL_FLAG_DONE[] = "DONE";
const char ADD_OPT_FILE[] = "FILE";
const char SEARCH_CMD[] = "SEARCH";
const char DELETE_CMD[] = "DELETE";
const char DISPLAY_CMD[] = "DISPLAY";
const char CLEAR_CMD[] = "CLEAR";
const char QUIT_CMD[] = "QUIT";
const char EXIT_CMD[] = "EXIT";

int main()
{
    RBT *rbt = new RBT();

    cout << "Red-Black Tree Part 1 & 2 (Insertion and Deletion)" << endl;

    // Command loop
    while (true)
    {
        // Display info and get user input
        cout << "---------------------------------------------------" << endl;
        cout << "ADD, DISPLAY, SEARCH, DELETE, CLEAR, or QUIT | EXIT" << endl;
        cout << " > ";
        char cmd[8];
        cin >> cmd;

        // Compare commands
        if (strcmp(cmd, ADD_CMD) == 0) // Adding numbers
        {
            // Display info and get user input
            cout << "MANUAL or FILE" << endl;
            cout << " > ";
            char opt[7];
            cin >> opt;

            // Compare command options
            if (strcmp(opt, ADD_OPT_MANUAL) == 0) // Manual input
            {
                cout << "Enter space-separated integers to add to the heap. Type \"DONE\" when finished." << endl;

                // Useful variables
                char input[17];
                char count = 0;
                int skipped = 0;
                while (true) // Continuously get space-separated user input
                {
                    cin >> input;
                    if (strcmp(input, ADD_MANUAL_FLAG_DONE) == 0) // The user indicated that they're done inputting numbers
                    {
                        break;
                    }
                    int value;
                    sscanf(input, "%d", &value);   // Scan the input for numbers
                    if (value <= 0 || value > 999) // We only want numbers between 0 and 999 (inclusive)
                    {
                        skipped++;
                    }
                    else
                    {
                        rbt->add(value);
                    }
                    count++;
                }
                if (skipped > 0)
                {
                    cout << "Warning: " << skipped << " numbers were skipped.  Make sure your numbers are between 1 and 1000, exclusive." << endl;
                }
                cout << "Added " << (count - skipped) << " numbers." << endl;
            }
            if (strcmp(opt, ADD_OPT_FILE) == 0) // File input
            {
                // Prompt user for file name
                cout << "Enter file name > ";
                char filename[261];
                cin >> filename;

                // Get all numbers in the file (space separated)
                cout << "Reading in numbers... ";
                vector<int> numbers;
                int numberCount = 0;

                ifstream numbersFile(filename); // Create the file stream
                if (numbersFile.is_open())      // If we can access the file
                {
                    // Continuously read space-separated integers from the file until the end of the stream is reached
                    int val;
                    while (!numbersFile.eof())
                    {
                        numbersFile >> val;
                        numbers.push_back(val);
                        numberCount++;
                    }
                    numbersFile.close();

                    // Sort through all the numbers to make sure they're valid
                    int skipped = 0;
                    for (int i = 0; i < numberCount; i++)
                    {
                        if (numbers[i] <= 0 || numbers[i] > 1000)
                        {
                            skipped++;
                        }
                        else
                        {
                            rbt->add(numbers[i]);
                        }
                    }

                    if (skipped > 0)
                    {
                        cout << "Warning: " << skipped << " numbers were skipped.  Make sure your numbers are between 1 and 999, inclusive." << endl;
                    }
                    cout << "Added " << (numberCount - skipped) << " numbers." << endl;
                }
                else
                {
                    cout << "Failed to open file: " << filename << endl;
                }
            }
        }
        if (strcmp(cmd, SEARCH_CMD) == 0)
        {
            cout << "Enter a number to search for: ";
            int number;
            cin >> number;
            bool found = rbt->search(number);
            if (found)
            {
                cout << "The value " << number << " was found!" << endl;
            }
            else
            {
                cout << "The value " << number << " was not found!" << endl;
            }
        }
        if (strcmp(cmd, DELETE_CMD) == 0)
        {
            cout << "Enter a number to delete: " << endl;
            int number;
            cin >> number;
            bool result = rbt->remove(number);
            if (result)
            {
                cout << number << " successfully removed." << endl;
            }
            else
            {
                cout << "Failed to remove " << number << "." << endl;
            }
        }
        if (strcmp(cmd, DISPLAY_CMD) == 0) // Display the RBT
        {
            rbt->display();
        }
        if (strcmp(cmd, CLEAR_CMD) == 0) // Clear the RBT
        {
            delete rbt;
            rbt = new RBT();
            cout << "Cleared the tree!" << endl;
        }
        if (strcmp(cmd, QUIT_CMD) == 0 || strcmp(cmd, EXIT_CMD) == 0) // Quit the program
        {
            break;
        }
    }

    delete rbt;
    return 0;
}