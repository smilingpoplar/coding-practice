//
//  design-circular-deque
//  https://leetcode.com/problems/design-circular-deque/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class MyCircularDeque {
    vector<int> data;
    int size = 0, capacity;
    int head = 0, tail;
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) : data(k) {
        capacity = k;
        tail = k - 1;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (isFull()) return false;
        head = (head - 1 + capacity) % capacity;
        data[head] = value;
        size++;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (isFull()) return false;
        tail = (tail + 1) % capacity;
        data[tail] = value;
        size++;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (isEmpty()) return false;
        head = (head + 1) % capacity;
        size--;
        return true;        
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (isEmpty()) return false;
        tail = (tail - 1 + capacity) % capacity;
        size--;
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if (isEmpty()) return -1;
        return data[head];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if (isEmpty()) return -1;
        return data[tail];
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return size == 0;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return size == capacity;
    }
};
int main(int argc, const char * argv[]) {
    return 0;
}
