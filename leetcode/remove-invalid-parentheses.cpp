//
//  remove-invalid-parentheses
//  https://leetcode.com/problems/remove-invalid-parentheses/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        search(s, 0, 0, "()", ans);
        return ans;
    }
    
    void search(const string &s, int idx, int lastRmIdx, const string &paren, vector<string> &ans) { 
        // 先从左往右扫，确保多出的左括号数leftDiff>=0；
        //   再从右往左扫，确保多出的右括号数>=0（从右往左就是将原串取反、改查右括号）。
        // 从左往右遇到leftDiff<0时前缀串不合法，要从[lastRmIdx..i]间删掉一个')'，lastRmIdx是上次删除位置。
        //   将删除限制在[lastRmIdx..i]间（而不是在[0..i]间），是为防止因删除顺序不同而使剩下括号串重复。
        // 删除时遇到连续')'时只删第一个，也是为了防止剩下括号串重复。
        int leftDiff = 0;
        for (int i = idx; i < s.size(); i++) {
            if (s[i] == paren[0]) leftDiff++;
            else if (s[i] == paren[1]) leftDiff--;
            if (leftDiff >= 0) continue;
            // [lastRmIdx..i]间有个')'要删除，只删连续')'的第一个
            for (int j = lastRmIdx; j <= i; j++) {
                if (s[j] == paren[1] && (j == lastRmIdx || s[j-1] != s[j])) {
                    // 删除s[j]，递归从i开始（原i+1因删除前移）
                    search(s.substr(0, j) + s.substr(j + 1), i, j, paren, ans);
                }
            }
            return; // 不删除')'，串已无效，后面不用再看
        }

        string reversed(s.rbegin(), s.rend());
        if (paren[0] == '(') search(reversed, 0, 0, ")(", ans);
        else ans.push_back(reversed);
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
