#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>

#include "heap.h"

using namespace std;

/*
    Function comments are in heap.h.

    Other comments that are necessary to explain the code are included in this file.
*/

Heap::Heap(int capacity)
{
    heap = new int[capacity];
    heapSize = 0;
    arraySize = capacity;
}

Heap::~Heap()
{
    delete[] heap;
}

int Heap::parent(int i)
{
    return (i - 1) / 2;
}

int Heap::left(int i)
{
    return 2 * i + 1;
}

int Heap::right(int i)
{
    return 2 * i + 2;
}

void Heap::swap(int &a, int &b)
{
    // Because we're passing in the integers by reference, they'll update globally
    int temp = a;
    a = b;
    b = temp;
}

void Heap::maxHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int largest = i;

    if (l < heapSize && heap[l] > heap[i])
    {
        largest = l;
    }

    if (r < heapSize && heap[r] > heap[largest])
    {
        largest = r;
    }

    if (largest != i)
    {
        swap(heap[i], heap[largest]);
        maxHeapify(largest);
    }
}

// Unused.  See heap.h
void Heap::buildMaxHeap()
{
    for (int i = (heapSize - 1) / 2; i >= 0; i--)
    {
        maxHeapify(i);
    }
}

void Heap::insert(int value)
{
    if (heapSize == arraySize)
    {
        cout << "Heap is full!" << endl;
        return;
    }

    heap[heapSize] = value; // Insert value at the end of the array

    int i = heapSize; // Start at the end of the array
    while (i > 0 && heap[i] > heap[parent(i)]) // Continue until we're at the root node or the new value is correctly placed
    {
        swap(heap[i], heap[parent(i)]);
        i = parent(i); // Work backwards to the current node's parent.
    }

    heapSize++;
}

int Heap::extractMax()
{
    if (heapSize == 0)
    {
        cout << "Heap is empty!" << endl;
        return -1;
    }

    int max = heap[0]; // Retrieve the root node
    heap[0] = heap[heapSize - 1]; // Set the root node to the last node in the array
    heapSize--;
    maxHeapify(0); // Start re-heaping at the very top of the array
    return max;
}

void Heap::printHeap(int i, int depth) {
    // If the index is greater than the heap size
    if (i >= this->getHeapSize()) return;

    // Get both the left and the right
    int right = 2 * i + 2;
    int left = 2 * i + 1;

    // Print the children of the right node first
    printHeap(right, depth + 1);

    // Set indentation for the current node
    cout << setw(depth * 5) << ""; // Adds indentation
    cout << heap[i] << endl;

    // Print the children of the left node second
    printHeap(left, depth + 1);
}


