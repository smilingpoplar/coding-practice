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
    // https://leetcode.com/problems/remove-invalid-parentheses/discuss/75027/Easy-Short-Concise-and-Fast-Java-DFS-3-ms-solution
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        search(s, 0, 0, "()", ans);
        return ans;
    }
    
    void search(const string &s, int idx, int lastRmIdx, const string &paren, vector<string> &ans) { 
        int leftDiff = 0;
        for (int i = idx; i < s.size(); i++) {
            if (s[i] == paren[0]) leftDiff++;
            else if (s[i] == paren[1]) leftDiff--;
            if (leftDiff >= 0) continue;
            // i前面有个')'要删除，只删除连续')'的第一个
            for (int j = lastRmIdx; j <= i; j++) {
                if (s[j] == paren[1] && (j == lastRmIdx || s[j-1] != paren[1])) {
                    search(s.substr(0, j) + s.substr(j + 1), i, j, paren, ans);
                }
            }
            return; // 不删除')'的话，后面已无效不用考虑
        }

        string reversed(s.rbegin(), s.rend());
        if (paren[0] == '(') search(reversed, 0, 0, ")(", ans);
        else ans.push_back(reversed);
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
