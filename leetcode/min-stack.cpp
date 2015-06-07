//
//  min-stack
//  https://leetcode.com/problems/min-stack/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class MinStack {
public:
    // 用两个栈，一个栈存储所有值，一个栈存储当前最小值
    void push(int x) {
        if (minStack.empty() || x <= minStack.back()) minStack.push_back(x);
        stack.push_back(x);
    }
    
    void pop() {
        if (stack.back() == minStack.back()) minStack.pop_back();
        stack.pop_back();
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        return minStack.back();
    }
    
private:
    vector<int> stack;    // 存储所有值
    vector<int> minStack; // 存储当前最小值
};

int main(int argc, const char * argv[]) {
    MinStack minStack;
    minStack.push(1);
    minStack.push(2);
    minStack.push(3);
    minStack.pop();
    cout << minStack.top() << endl;
    cout << minStack.getMin() << endl;
    
    return 0;
}
