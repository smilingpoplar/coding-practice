//
//  min-stack
//  https://leetcode.com/problems/min-stack/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;

class MinStack {
    stack<int> stk;    // 存储所有值
    stack<int> minStk; // 存储当前最小值
public:
    /** initialize your data structure here. */
    MinStack() {    
    }

    void push(int x) {
        if (minStk.empty() || x <= minStk.top()) minStk.push(x);
        stk.push(x);
    }
    
    void pop() {
        if (stk.top() == minStk.top()) minStk.pop();
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minStk.top();
    }
};

int main(int argc, const char * argv[]) {
    MinStack minStk;
    minStk.push(1);
    minStk.push(2);
    minStk.push(3);
    minStk.pop();
    cout << minStk.top() << endl;
    cout << minStk.getMin() << endl;
    
    return 0;
}
