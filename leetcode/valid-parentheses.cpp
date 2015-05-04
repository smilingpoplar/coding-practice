//
//  valid-parentheses.cpp
//  https://leetcode.com/problems/valid-parentheses/
//
//  Created by smilingpoplar on 15/5/4.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        const string left = "([{";
        const string right = ")]}";
        stack<char> stack;
        for (char c : s) {
            if (left.find(c) != string::npos) {
                stack.push(c);
            } else {
                if (stack.empty()) return false;
                char top = stack.top();
                stack.pop();
                if (top != left[right.find(c)]) return false;
            }
        }
        
        return stack.empty();
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.isValid("()[]{}");
    
    return 0;
}
