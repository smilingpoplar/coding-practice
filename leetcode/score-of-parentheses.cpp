//
//  score-of-parentheses
//  https://leetcode.com/problems/score-of-parentheses/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int scoreOfParentheses(string S) {
        // 深度depth的"()"贡献2^depth分
        int depth = 0, ans = 0;
        for (int i = 0; i < S.size(); i++) {
            if (S[i] == '(') depth++;
            else {
                depth--;
                if (S[i-1] == '(') ans += 1 << depth;
            }
        }
        return ans;
    }
};
int main(int argc, const char * argv[]) {
    return 0;
}
