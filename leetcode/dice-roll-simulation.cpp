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
        // 设dp[i][j]表示取i次数、第i次取数为j的不同序列数，
        // 要求不能有超过r=rollMax[j]个j，
        // dp[i][j] = dp[i-1][not_j] /*连续1个j*/ + dp[i-2][not_j] /*连续2个j*/ + ... + dp[i-r][not_j] /*连续r个j*/，
        //    = sum{ dp[i-k][not_j] }, k在[1..rollMax[j]]
        // 令sum[i]表示取i次数的不同序列数，则sum[i]=sum{ dp[i][j], for all j }，sum{dp[i][not_j]}=sum[i]-dp[i][j]，
        // 所以dp[i][j] = sum{ sum[i-k]-dp[i-k][j] }
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
