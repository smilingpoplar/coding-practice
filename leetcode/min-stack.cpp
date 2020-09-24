//
//  min-stack
//  https://leetcode.com/problems/min-stack/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;

class MinStack {
    stack<int> nums;
    stack<int> mins;
public:
    /** initialize your data structure here. */
    MinStack() {    
    }

    void push(int x) {
        if (mins.empty() || x <= mins.top()) mins.push(x);
        nums.push(x);
    }
    
    void pop() {
        if (nums.top() == mins.top()) mins.pop();
        nums.pop();
    }
    
    int top() {
        return nums.top();
    }
    
    int getMin() {
        return mins.top();
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
