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
    stack<int> nums;
    stack<int> maxs;
public:
    /** initialize your data structure here. */
    MaxStack() {
    }
    
    void push(int x) {
        if (maxs.empty() || x >= maxs.top()) maxs.push(x);
        nums.push(x);
    }
    
    int pop() {
        if (nums.top() == maxs.top()) maxs.pop();
        int ans = top(); nums.pop();
        return ans;
    }
    
    int top() {
        return nums.top();
    }
    
    int peekMax() {
        return maxs.top();
    }
    
    int popMax() {
        int ans = peekMax();
        stack<int> buffer;
        while (top() != ans) {
            buffer.push(pop());
        }
        maxs.pop();
        nums.pop();
        while (!buffer.empty()) {
            push(buffer.top());
            buffer.pop();
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
