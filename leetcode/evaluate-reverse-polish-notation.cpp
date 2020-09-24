//
//  evaluate-reverse-polish-notation
//  https://leetcode.com/problems/evaluate-reverse-polish-notation/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (auto &token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                if (stk.size() < 2) return 0;
                int val2 = stk.top(); stk.pop();
                int val1 = stk.top(); stk.pop();
                if (token == "+") stk.push(val1 + val2);
                else if (token == "-") stk.push(val1 - val2);
                else if (token == "*") stk.push(val1 * val2);
                else if (token == "/") stk.push(val1 / val2);
            } else {
                stk.push(stoi(token));
            }
        }
        return stk.top();
    }
};

int main(int argc, const char * argv[]) {
    vector<string> tokens = {"2", "1", "+", "3", "*"};
    Solution solution;
    cout << solution.evalRPN(tokens);
 
    return 0;
}
