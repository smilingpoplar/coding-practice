//
//  longest-valid-parentheses
//  https://leetcode.com/problems/longest-valid-parentheses/
//
//  Created by smilingpoplar on 15/6/9.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        stack<int> stk;
        stk.push(-1); // 不变式：栈顶记录有效串前一个位置
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                stk.push(i);
            } else { // ')'
                stk.pop(); // 正常是匹配掉
                if (!stk.empty()) ans = max(ans, i - stk.top());
                else stk.push(i);
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.longestValidParentheses("()(())");

    return 0;
}
