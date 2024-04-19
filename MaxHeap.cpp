// MaxHeap.cpp
#include "MaxHeap.h"
#include <iostream>
#include <algorithm>

#define HEAP_MIN_SIZE 20

MaxHeap::MaxHeap() {
    capacity = HEAP_MIN_SIZE;
    heapArray = new int[capacity];
    size = 0;
}

MaxHeap::MaxHeap(int* values, int count) {
    capacity = count + HEAP_MIN_SIZE;
    heapArray = new int[capacity];
    size = count;
    for (int i = 0; i < count; ++i) {
        heapArray[i] = values[i];
    }

    // Heapify the array
    for (int i = (size / 2) - 1; i >= 0; --i) {
        heapify(i);
    }
}

MaxHeap::~MaxHeap() {
    delete[] heapArray;
}

void MaxHeap::resize(int newCapacity) {
    int* newArray = new int[newCapacity];
    for (int i = 0; i < size; ++i) {
        newArray[i] = heapArray[i];
    }
    delete[] heapArray;
    heapArray = newArray;
    capacity = newCapacity;
}

void MaxHeap::heapify(int index) {
    int largest = index;
    int left = getLeftChild(index);
    int right = getRightChild(index);

    if (left < size && heapArray[left] > heapArray[largest]) {
        largest = left;
    }
    if (right < size && heapArray[right] > heapArray[largest]) {
        largest = right;
    }

    if (largest != index) {
        std::swap(heapArray[index], heapArray[largest]);
        heapify(largest);
    }
}

int MaxHeap::getParent(int index) const {
    return (index - 1) / 2;
}

int MaxHeap::getLeftChild(int index) const {
    return 2 * index + 1;
}

int MaxHeap::getRightChild(int index) const {
    return 2 * index + 2;
}

void MaxHeap::offer(int value) {
    if (size == capacity) {
        resize(2 * capacity);
    }
    heapArray[size++] = value;
    int current = size - 1;
    while (current > 0 && heapArray[current] > heapArray[getParent(current)]) {
        std::swap(heapArray[current], heapArray[getParent(current)]);
        current = getParent(current);
    }
}

int MaxHeap::poll() {
    if (isEmpty()) {
        throw std::out_of_range("Heap is empty");
    }
    int maxVal = heapArray[0];
    heapArray[0] = heapArray[--size];
    heapify(0);
    if (size < capacity / 2 && capacity > HEAP_MIN_SIZE) {
        resize(capacity / 2);
    }
    return maxVal;
}

bool MaxHeap::isEmpty() const {
    return size == 0;
}

int MaxHeap::peek() const {
    if (isEmpty()) {
        throw std::out_of_range("Heap is empty");
    }
    return heapArray[0];
}

std::vector<int> MaxHeap::sorted() const {
    std::vector<int> sortedVec(size);
    std::copy(heapArray, heapArray + size, sortedVec.begin());
    std::sort(sortedVec.begin(), sortedVec.end(), std::greater<int>());
    return sortedVec;
}

MaxHeap::MaxHeap(const MaxHeap& other) {
    capacity = other.capacity;
    size = other.size;
    heapArray = new int[capacity];
    for (int i = 0; i < size; ++i) {
        heapArray[i] = other.heapArray[i];
    }
}

MaxHeap& MaxHeap::operator=(const MaxHeap& other) {
    if (this != &other) {
        delete[] heapArray;
        capacity = other.capacity;
        size = other.size;
        heapArray = new int[capacity];
        for (int i = 0; i < size; ++i) {
            heapArray[i] = other.heapArray[i];
        }
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const MaxHeap& heap) {
    for (int i = 0; i < heap.size; ++i) {
        os << heap.heapArray[i] << " ";
    }
    return os;
}