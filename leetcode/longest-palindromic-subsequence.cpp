//
//  longest-palindromic-subsequence
//  https://leetcode.com/problems/longest-palindromic-subsequence/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        // 设dp[i][j]表示s[i..j]的最长回文子序列长，0<=i<=j<N
        // 若s[i]==s[j]，dp[i][j]=dp[i+1][j-1]+(i==j)?1:2；
        // 否则，dp[i][j]=max(dp[i+1][j], dp[i][j-1])
        const int N = s.size();
        vector<vector<int>> dp(N, vector<int>(N, 0));
        for (int i = N - 1; i >= 0; i--) {
            for (int j = i; j < N; j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = (i == j) ? 1 : 2;
                    if (i + 1 <= j - 1) dp[i][j] += dp[i+1][j-1];
                } else {
                    if (i + 1 < N) dp[i][j] = max(dp[i][j], dp[i+1][j]);
                    if (j - 1 >= 0) dp[i][j] = max(dp[i][j], dp[i][j-1]);
                }
            }
        }
        return dp[0][N-1];
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
