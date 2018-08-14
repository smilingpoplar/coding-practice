//
//  minimum-ascii-delete-sum-for-two-strings
//  https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        // 类似编辑距离，设dp[i][j]表示s1[0..i-1]和s2[0..j-1]的最小ascii删除和。
        // 若s1[i-1]==s2[j-1]，dp[i][j] = dp[i-1][j-1]；
        // 若s1[i-1]!=s2[j-1]，dp[i][j] = min(dp[i-1][j]+s1[i-1], dp[i][j-1]+s2[j-1])
        // 初始dp[0][0]=0，所求是dp[M][N]
        const int M = s1.size(), N = s2.size();
        vector<vector<int>> dp(M + 1, vector<int>(N + 1));
        dp[0][0] = 0;
        for (int i = 1; i <= M; i++) {
            dp[i][0] = dp[i-1][0] + s1[i-1];
        }
        for (int j = 1; j <= N; j++) {
            dp[0][j] = dp[0][j-1] + s2[j-1];
        }
        for (int i = 1; i <= M; i++) {
            for (int j = 1; j <= N; j++) {
                if (s1[i-1] == s2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = min(dp[i-1][j] + s1[i-1], dp[i][j-1] + s2[j-1]);
                }
            }
        }
        return dp[M][N];
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
