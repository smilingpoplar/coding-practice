//
//  implement-queue-using-stacks
//  https://leetcode.com/problems/implement-queue-using-stacks/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class MyQueue {
    stack<int> in, out;

    void moveIfOutStackEmpty() {
        if (out.empty()) {
            while (!in.empty()) {
                out.push(in.top());
                in.pop();
            }
        }
    }
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        in.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        moveIfOutStackEmpty();
        if (out.empty()) return INT_MIN;
        int ans = out.top();
        out.pop();
        return ans;
    }
    
    /** Get the front element. */
    int peek() {
        moveIfOutStackEmpty();
        if (out.empty()) return INT_MIN;
        return out.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return out.empty() && in.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */

int main(int argc, const char * argv[]) {
    return 0;
}
