// MaxHeap.h
#ifndef MAXHEAP_H
#define MAXHEAP_H

#include <vector>
#include <stdexcept>
#include <algorithm>

class MaxHeap {
private:
    int* heapArray;
    int capacity;
    int size;

    void resize(int newCapacity);
    void heapify(int index);
    int getParent(int index) const;
    int getLeftChild(int index) const;
    int getRightChild(int index) const;

public:
    MaxHeap();
    MaxHeap(int* values, int count);
    ~MaxHeap();

    void offer(int value);
    int poll();
    bool isEmpty() const;
    int peek() const;
    std::vector<int> sorted() const;

    // Copy constructor and assignment operator
    MaxHeap(const MaxHeap& other);
    MaxHeap& operator=(const MaxHeap& other);

    // Overload << for printing heap
    friend std::ostream& operator<<(std::ostream& os, const MaxHeap& heap);
};

#endif // MAXHEAP_H