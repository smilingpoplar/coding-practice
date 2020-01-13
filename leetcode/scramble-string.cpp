//
//  scramble-string
//  https://leetcode.com/problems/scramble-string/
//
//  Created by smilingpoplar on 15/6/8.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        // 设dp[n][i][j]表示两个等长串s1[i..i+n)和s2[j..j+n)是否scramble
        // 每个串可由二叉树分成两部分，遍历1<=k<n种划分可能（k表示左串长），
        // dp[n][i][j] = ( dp[k][i][j] && dp[n-k][i+k][j+k] ) || ( dp[k][i][j+n-k] && dp[n-k][i+k][j] )
        // 初始n==1时，dp[1][i][j] = s1[i]==s2[j]
        const int N = s1.size();
        if (N != s2.size()) return false;
        vector<vector<vector<bool>>> dp(N + 1, vector<vector<bool>>(N, vector<bool>(N, false)));
        
        // n==1
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                dp[1][i][j] = s1[i] == s2[j];
            }
        }
        
        for (int n = 2; n <= N; n++) {
            for (int i = 0; i + n <= N; i++) {
                for (int j = 0; j + n <= N; j++) {
                    for (int k = 1; k < n && !dp[n][i][j]; k++) {
                        dp[n][i][j] = ( dp[k][i][j] && dp[n-k][i+k][j+k] ) 
                                    || ( dp[k][i][j+n-k] && dp[n-k][i+k][j] );
                    }
                }
            }
        }
        
        return dp[N][0][0];
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.isScramble("abc", "acb");

    return 0;
}
