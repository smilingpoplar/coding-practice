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
        vector<int> lefts;  // 未匹配'('的索引
        int lastRight = -1; // 最后未匹配')'的索引
        int longest = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                lefts.push_back(i);
            } else { // ')'
                if (!lefts.empty()) {
                    lefts.pop_back(); // 匹配
                    int lastEnd = !lefts.empty() ? lefts.back() : lastRight;
                    longest = max(longest, i - lastEnd);
                } else {
                    lastRight = i;
                }
            }
        }
        return longest;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.longestValidParentheses("()(())");

    return 0;
}
