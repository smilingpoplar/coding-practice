//
//  evaluate-reverse-polish-notation
//  https://leetcode.com/problems/evaluate-reverse-polish-notation/
//
//  Created by smilingpoplar on 15/6/17.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> stack;
        for (const auto &token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                if (stack.size() < 2) return 0;
                int value2 = stack.back();
                stack.pop_back();
                int value1 = stack.back();
                stack.pop_back();
                if (token == "+") stack.push_back(value1 + value2);
                else if (token == "-") stack.push_back(value1 - value2);
                else if (token == "*") stack.push_back(value1 * value2);
                else if (token == "/") stack.push_back(value1 / value2);
            } else {
                stack.push_back(stoi(token));
            }
        }
        return stack.back();
    }
};

int main(int argc, const char * argv[]) {
    vector<string> tokens = {"2", "1", "+", "3", "*"};
    Solution solution;
    cout << solution.evalRPN(tokens);
 
    return 0;
}