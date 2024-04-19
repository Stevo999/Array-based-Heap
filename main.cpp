// main.cpp
#include <iostream>
#include "MaxHeap.h"

int main() {
    // Test the default constructor
    MaxHeap heap1;
    std::cout << "Heap 1 (default constructor): " << heap1 << std::endl;

    // Test the constructor with an array
    int values[] = {10, 20, 30, 40, 50};
    int count = sizeof(values) / sizeof(int);
    MaxHeap heap2(values, count);
    std::cout << "Heap 2 (array constructor): " << heap2 << std::endl;

    // Test the offer() method
    heap1.offer(15);
    heap1.offer(25);
    heap1.offer(35);
    std::cout << "Heap 1 after offers: " << heap1 << std::endl;

    // Test the poll() method
    std::cout << "Polling from Heap 1: " << heap1.poll() << std::endl;
    std::cout << "Heap 1 after poll: " << heap1 << std::endl;

    // Test the peek() method
    std::cout << "Peeking at Heap 2: " << heap2.peek() << std::endl;

    // Test the sorted() method
    std::vector<int> sortedVec = heap2.sorted();
    std::cout << "Sorted Heap 2: ";
    for (int val : sortedVec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Test the copy constructor and assignment operator
    MaxHeap heap3(heap2);
    std::cout << "Heap 3 (copy constructor): " << heap3 << std::endl;

    MaxHeap heap4 = heap1;
    std::cout << "Heap 4 (assignment operator): " << heap4 << std::endl;

    return 0;
}