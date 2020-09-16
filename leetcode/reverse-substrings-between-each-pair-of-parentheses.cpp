//
//  reverse-substrings-between-each-pair-of-parentheses
//  https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        string ans;
        stack<int> open;
        for (char c : s) {
            if (c == '(') {
                open.push(ans.size());                
            } else if (c == ')') {
                int pos = open.top();  open.pop();
                reverse(ans.begin() + pos, ans.end());
            } else {
                ans += c;
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
