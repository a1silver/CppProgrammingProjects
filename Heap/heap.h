#include <iostream>
#include <algorithm>

using namespace std;

class Heap
{
private:
    int *heap;
    int heapSize;
    int arraySize;

    // Helper functions
    int parent(int i);

    int left(int i);

    int right(int i);

    void swap(int &a, int &b);

    // Heapify operations
    void maxHeapify(int i);

    void buildMaxHeap();

public:
    Heap(int capacity);
    ~Heap();

    int getMax();

    void insert(int value);

    int extractMax();

    void printHeap(int n, int i, int depth);

    int getHeapSize() const
    {
        return heapSize;
    }

    bool isHeapFull() const {
        return heapSize == arraySize;
    }
};
