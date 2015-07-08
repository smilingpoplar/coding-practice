//
//  implement-queue-using-stacks
//  https://leetcode.com/problems/implement-queue-using-stacks/
//
//  Created by smilingpoplar on 15/7/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        in.push_back(x);
    }
    
    // Removes the element from in front of queue.
    void pop(void) {
        if (out.empty()) {
            while (!in.empty()) {
                out.push_back(in.back());
                in.pop_back();
            }
        }
        if (out.empty()) return;
        out.pop_back();
    }
    
    // Get the front element.
    int peek(void) {
        if (out.empty()) {
            while (!in.empty()) {
                out.push_back(in.back());
                in.pop_back();
            }
        }
        if (out.empty()) return INT_MIN;
        return out.back();
    }
    
    // Return whether the queue is empty.
    bool empty(void) {
        return out.empty() && in.empty();
    }

private:
    vector<int> in;
    vector<int> out;
};

int main(int argc, const char * argv[]) {
    Queue q;
    q.push(1);
    q.push(2);
    q.pop();
    cout << q.peek();
    
    return 0;
}
