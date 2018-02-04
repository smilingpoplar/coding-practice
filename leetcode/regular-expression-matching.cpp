//
//  regular-expression-matching
//  https://leetcode.com/problems/regular-expression-matching/
//
//  Created by smilingpoplar on 15/6/4.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

/*
class Solution {
public:
    bool isMatch(string s, string p) {
        return isMatch(s, 0, p, 0);
    }
    
    bool isMatch(const string &s, int si, string &p, int pi) {
        if (pi == p.size()) return si == s.size();
        bool matchOne = si < s.size() && (s[si] == p[pi] || p[pi] == '.');
        if (pi + 1 < p.size() && p[pi + 1] == '*') {
            return isMatch(s, si, p, pi + 2) || (matchOne && isMatch(s, si + 1, p, pi));
        }
        return matchOne && isMatch(s, si + 1, p, pi + 1);
    }
};
*/

class Solution {
public:
    bool isMatch(string s, string p) {
        // 设dp[i][j]表示s[i..]和p[j..]匹配，0<=i<=M，0<=j<=N，则
        // matchOne = i<M && (s[i]==p[j] || p[j]=='.')
        // 当p[j+1]=='*'
        //     dp[i][j] = dp[i][j+2] // 匹配0次
        //     dp[i][j] ||= matchOne && dp[i+1][j] // 递归匹配多次
        // 当p[j+1]!='*'
        //     dp[i][j] = matchOne && dp[i+1][j+1]
        
        const int M = s.size();
        const int N = p.size();
        vector<vector<bool>> dp(M + 1, vector<bool>(N + 1, false));
        dp[M][N] = true; // dp[][N]的其他情况为false
        
        for (int i = M; i >= 0; i--) {
            for (int j = N - 1; j >= 0; j--) {
                bool matchOne = i < M && (s[i] == p[j] || p[j] == '.');
                if (j + 2 <= N && p[j+1] == '*') {
                    dp[i][j] = dp[i][j+2] || (matchOne && dp[i+1][j]);
                } else {
                    dp[i][j] = matchOne && dp[i+1][j+1];
                }
            }
        }
        return dp[0][0];
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.isMatch("aaa", "ab*a");
    
    return 0;
}
