#include <iostream>
#include <algorithm>

using namespace std;

class Heap
{
private:
    /*
        The array that stores all of the values.
        It's dynamically allocated so users can specify their own max heap size.
    */
    int *heap;
    int heapSize;
    int arraySize;

    // Get the left, right, and parent nodes of the given index
    int parent(int i);
    int left(int i);
    int right(int i);

    // Swap two indices of the array.  This helper function's only purpose is to clean up code.
    void swap(int &a, int &b);

    // Re-heap the array starting at the given index
    void maxHeapify(int i);

    // This function was originally used for a statically allocated int array, but is now unsed because dynamic allocation was implemented.
    void buildMaxHeap();

public:
    Heap(int capacity);
    ~Heap();

    // The most important operations for a max heap
    void insert(int value);
    int extractMax();

    /*
        Display the heap in a nice tree structure.

        This function prints the tree from top to bottom, so the right-side nodes will be displayed first (on top), and the left-side nodes will be displayed second (on the bottom).
    */
    void printHeap(int i, int depth);

    // Getters
    int getMax() const { return heap[0]; }
    int getHeapSize() const { return heapSize; }
    bool isHeapFull() const { return heapSize == arraySize; }
    int peek(int i) const { return this->heap[i]; }
};

/*
    This is the Heap class.  It represents a Max Heap.  A max heap is a binary tree where every node is larger than its child.

    This class defines the crucial operations for a max heap - insertion and extraction.  
    Insertion works by placing the new value at the end of the array and "sifting up" through all parent nodes until the value is correctly placed.
    Extraction works by retrieving the root node, or largest node.  It then replaces the root node with the node at the end of the array.  Re-heaping then begins at the top of the array and "sifts down" until the all values in the heap are correctly placed.
*/
