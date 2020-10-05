//
//  longest-valid-parentheses
//  https://leetcode.com/problems/longest-valid-parentheses/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        stack<int> stk; // 没匹配掉的压入栈中，保存下标
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ')' && !stk.empty() && s[stk.top()] == '(') {
                stk.pop();
                int lastMismatch = stk.empty() ? -1 : stk.top();
                ans = max(ans, i - lastMismatch); // 前开后闭
            } else {
                stk.push(i);
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
