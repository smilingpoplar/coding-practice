//
//  minimum-ascii-delete-sum-for-two-strings
//  https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        // 设dp[i][j]表示s1[i..]和s2[j..]的最小ascii删除和。
        // 若s1[i]==s2[j]，dp[i][j] = dp[i+1][j+1]
        // 若s1[i]!=s2[j]，dp[i][j] = min(s1[i]+dp[i+1][j], s2[j]+dp[i][j+1])
        // 初始dp[M][N]=0，所求dp[0][0]
        const int M = s1.size(), N = s2.size();
        vector<vector<int>> dp(M + 1, vector<int>(N + 1));
        dp[M][N] = 0;
        for (int i = M - 1; i >= 0; i--) {
            dp[i][N] = s1[i] + dp[i+1][N];
        }
        for (int j = N - 1; j >= 0; j--) {
            dp[M][j] = s2[j] + dp[M][j+1];
        }

        for (int i = M - 1; i >= 0; i--) {
            for (int j = N - 1; j >= 0; j--) {
                if (s1[i] == s2[j]) {
                    dp[i][j] = dp[i+1][j+1];
                } else {
                    dp[i][j] = min(s1[i] + dp[i+1][j], s2[j] + dp[i][j+1]);
                }
            }
        }
        return dp[0][0];
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
