//
//  dice-roll-simulation
//  https://leetcode.com/problems/dice-roll-simulation/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        // 设dp[i][j]表示取i次数、第i次取数为j的子问题解
        // 要求不能有超过r=rollMax[j]个j，第i次前可以有连续[0..r-1]个j
        // dp[i][j] = dp[i-1][~j] + dp[i-2][~j] + ... + dp[i-r][~j]，
        // ~j表示非j的其他数。
        // 令sum[i]表示取i次数的子问题解，则dp[i][~j]=sum[i]-dp[i][j]
        const int MOD = 1e9 + 7;
        vector<vector<int>> dp(n+1, vector<int>(6, 0));
        vector<long> sum(n+1, 0);
        sum[0] = 1; // 取0次数有个空集{}
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 6; j++) {
                for (int k = 1; k <= rollMax[j] && i - k >= 0; k++) {
                    dp[i][j] = (dp[i][j] + sum[i-k] - dp[i-k][j] + MOD) % MOD;
                }
                sum[i] = (sum[i] + dp[i][j]) % MOD;
            }
        }
        return sum[n];
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
