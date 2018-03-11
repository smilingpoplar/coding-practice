//
//  max-stack
//  https://leetcode.com/problems/max-stack/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class MaxStack {
    stack<int> stk;
    stack<int> maxStk;
public:
    /** initialize your data structure here. */
    MaxStack() {
    }
    
    void push(int x) {
        int theMax = maxStk.empty() ? INT_MIN : peekMax();
        if (x > theMax) theMax = x;
        maxStk.push(theMax);
        stk.push(x);
    }
    
    int pop() {
        int ans = top();
        maxStk.pop();
        stk.pop();
        return ans;
    }
    
    int top() {
        return stk.top();
    }
    
    int peekMax() {
        return maxStk.top();
    }
    
    int popMax() {
        int ans = peekMax();
        stack<int> buffer;
        while (top() != ans) {
            buffer.push(pop());
        }
        maxStk.pop();
        stk.pop();
        while (!buffer.empty()) {
            push(buffer.top());
            buffer.pop();
        }
        return ans;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack obj = new MaxStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.peekMax();
 * int param_5 = obj.popMax();
 */

int main(int argc, const char * argv[]) {
    return 0;
}
