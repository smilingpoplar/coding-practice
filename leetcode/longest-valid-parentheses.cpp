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

/*
class Solution {
public:
    int longestValidParentheses(string s) {
        const int N = s.size();
        // 左括号数lefts、右括号数rights
        int lefts = 0, rights = 0, ans = 0;
        // 从左往右数的过程中确保lefts>=rights
        for (int i = 0; i < N; i++) {
            if (s[i] == '(') lefts++;
            else if (s[i] == ')') rights++;
            
            if (lefts == rights) { // 已配对
                ans = max(ans, 2 * lefts);
            } else if (lefts < rights) {
                lefts = rights = 0;
            }
        }
        // 从右往左数的过程中确保rights>=lefts
        lefts = rights = 0;
        for (int i = N - 1; i >= 0; i--) {
            if (s[i] == '(') lefts++;
            else if (s[i] == ')') rights++;
            
            if (lefts == rights) { // 已配对
                ans = max(ans, 2 * lefts);
            } else if (rights < lefts) {
                lefts = rights = 0;
            }
        }
        return ans;
    }
};
*/

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.longestValidParentheses("()(())");

    return 0;
}
