#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>

#include "heap.h"

using namespace std;

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

void Heap::buildMaxHeap()
{
    for (int i = (heapSize - 1) / 2; i >= 0; i--)
    {
        maxHeapify(i);
    }
}

int Heap::getMax()
{
    return heap[0];
}

void Heap::insert(int value)
{
    if (heapSize == arraySize)
    {
        cout << "Heap is full!" << endl;
        return;
    }

    heap[heapSize] = value;

    int i = heapSize;
    while (i > 0 && heap[i] > heap[parent(i)])
    {
        swap(heap[i], heap[parent(i)]);
        i = parent(i);
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

    int max = heap[0];
    heap[0] = heap[heapSize - 1];
    heapSize--;
    maxHeapify(0);
    return max;
}

void Heap::printHeap(int n, int i, int depth) {
    if (i >= n) return;

    int right = 2 * i + 2;
    int left = 2 * i + 1;

    printHeap(n, right, depth + 1);

    cout << setw(depth * 5) << ""; // Adds indentation
    cout << heap[i] << endl;

    printHeap(n, left, depth + 1);
}


