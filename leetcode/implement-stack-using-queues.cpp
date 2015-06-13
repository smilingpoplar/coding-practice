//
//  implement-stack-using-queues
//  https://leetcode.com/problems/implement-stack-using-queues/
//
//  Created by smilingpoplar on 15/6/13.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

class Stack {
public:
    // Push element x onto stack.
    void push(int x) { // O(n)时间
        _q.push(x);
        for (int i = 0; i < _q.size() - 1; ++i) {
            _q.push(_q.front());
            _q.pop();
        }
    }
    
    // Removes the element on top of the stack.
    void pop() {
        _q.pop();
    }
    
    // Get the top element.
    int top() {
        return _q.front();
    }
    
    // Return whether the stack is empty.
    bool empty() {
        return _q.empty();
    }
    
private:
    queue<int> _q;
};

int main(int argc, const char * argv[]) {
    Stack stack;
    stack.push(1);
    stack.push(2);
    cout << stack.top() << endl;
    stack.pop();
    cout << stack.top() << endl;
    
    return 0;
}
