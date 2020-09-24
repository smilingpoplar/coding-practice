//
//  validate-stack-sequences
//  https://leetcode.com/problems/validate-stack-sequences/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        int j = 0;
        for (int num : pushed) {
            stk.push(num);
            // num先入栈，栈顶与popped[j]相同时弹出
            while (!stk.empty() && stk.top() == popped[j]) {
                stk.pop();
                j++;
            }
        }
        return j == popped.size();
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
