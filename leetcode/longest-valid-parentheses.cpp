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
        const int N = s.size();
        int left = 0, right = 0; // 左括号数left，右括号数right
        // 从左往右数的过程中确保left>=right
        for (int i = 0; i < N; i++) {
            if (s[i] == '(') left++;
            else if (s[i] == ')') right++;
            
            if (left == right) { // 已配对
                ans = max(ans, 2 * left);
            } else if (left < right) {
                left = right = 0;
            }
        }
        // 从右往左数的过程中确保right>=left
        left = right = 0;
        for (int i = N - 1; i >= 0; i--) {
            if (s[i] == '(') left++;
            else if (s[i] == ')') right++;
            
            if (left == right) { // 已配对
                ans = max(ans, 2 * left);
            } else if (right < left) {
                left = right = 0;
            }
        }
        return ans;
    }
};

/*
class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        stack<int> stk;
        stk.push(-1); // 不变式：栈顶记录上一个无效串尾的位置
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                stk.push(i);
            } else { // ')'
                stk.pop(); // 总是匹配掉一个
                if (!stk.empty()) ans = max(ans, i - stk.top());
                else stk.push(i);
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
