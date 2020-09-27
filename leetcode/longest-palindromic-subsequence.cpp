//
//  longest-palindromic-subsequence
//  https://leetcode.com/problems/longest-palindromic-subsequence/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        // 设dp[i][j]表示s[i..j]的最长回文子序列长，0<=i<=j<N
        // 若s[i]==s[j]，dp[i][j]=dp[i+1][j-1]+2，i<j
        // 否则，dp[i][j]=max(dp[i+1][j], dp[i][j-1])
        // 初始dp[i][i]=1
        const int N = s.size();
        vector<vector<int>> dp(N, vector<int>(N, 0));
        for (int i = 0; i < N; i++) {
            dp[i][i] = 1;
        }

        for (int len = 2; len <= N; len++) {
            for (int i = 0; i + len <= N; i++) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i+1][j-1] + 2;
                } else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return dp[0][N-1];
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
