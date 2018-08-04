//
//  interleaving-string
//  https://leetcode.com/problems/interleaving-string/
//
//  Created by smilingpoplar on 15/5/2.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // 设dp[i][j]表示s1[0..i)和s2[0..j)能否交错出s3[0..i+j)
        // 若s1[i-1]==s3[i+j-1]，dp[i][j]=dp[i-1][j]；若s2[j-1]==s3[i+j-1]，dp[i][j]=dp[i][j-1]；
        // 否则dp[i][j]=false。初始dp[0][0]=true
        const int M = s1.size(), N = s2.size();
        if (s3.size() != M + N) return false;
        
        vector<vector<bool>> dp(M + 1, vector<bool>(N + 1, false));
        dp[0][0] = true;
        for (int i = 0; i <= M; i++) {
            for (int j = 0; j <= N; j++) {
                if (i > 0 && s1[i-1] == s3[i+j-1]) {
                    dp[i][j] = dp[i-1][j];
                    if (dp[i][j]) continue;
                }
                if (j > 0 && s2[j-1] == s3[i+j-1]) {
                    dp[i][j] = dp[i][j-1];
                }
            }
        }
        return dp[M][N];
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.isInterleave("aabcc", "dbbca", "aadbbcbcac");
    
    return 0;
}
