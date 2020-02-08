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
        const int N = s.size();
        stack<int> opened;
        string ans;
        for (int i = 0; i < N; i++) {
            if (s[i] == '(') {
                opened.push(ans.size());                
            } else if (s[i] == ')') {
                int j = opened.top();  opened.pop();
                reverse(ans.begin() + j, ans.end());
            } else {
                ans += s[i];
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
