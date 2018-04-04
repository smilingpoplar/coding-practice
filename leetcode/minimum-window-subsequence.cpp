//
//  minimum-window-subsequence
//  https://leetcode.com/problems/minimum-window-subsequence/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string minWindow(string S, string T) {
        // 设dp[i][j]=k表示在长i的S[0..i)中找长j的T[0..j)子序列（的最大起始索引k），
        // 找不到时k==-1，找到时S[k..i)是包含T[0..j)的最小窗口，即k是满足条件的最大起始索引。
        // 当S[i-1]==T[j-1]时，只需在S[0..i-1)中找T[0..j-1)，dp[i][j]=dp[i-1][j-1]
        // 当S[i-1]!=T[j-1]时，还需在S[0..i-1)中找T[0..j)，dp[i][j]=dp[i-1][j]
        // 初始dp[i][0]=i, dp[0][j>0]=-1。所求dp[M][N]。
        const int M = S.size(), N = T.size();
        vector<vector<int>> dp(M + 1, vector<int>(N + 1, -1));
        for (int i = 0; i <= M; i++) {
            dp[i][0] = i;
        }

        int minlen = INT_MAX, start = -1;
        for (int i = 1; i <= M; i++) {
            for (int j = 1; j <= N; j++) {
                dp[i][j] = (S[i-1] == T[j-1]) ? dp[i-1][j-1] : dp[i-1][j];
            }
            
            if (dp[i][N] != -1) {
                int len = i - dp[i][N];
                if (len < minlen) {
                    minlen = len;
                    start = dp[i][N];
                }
            }
        }
        return (minlen == INT_MAX) ? "" : S.substr(start, minlen);        
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
