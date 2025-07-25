//
//  divide-number
//  将整数n分成k份，且每份不能为空，任意两个方案不能相同（不考虑顺序）。
//

#include <iostream>

using namespace std;

class Solution {
public:
    int divideNumber(int n, int k) {
        // 设dp[i][j]表示最大方案数，0<=i<=n, 0<=j<=k
        // 若j个数中至少有一个是1，方案数为 dp[i-1][j-1]
        // 若j个数中没有一个数是1，则所有j个数都减去1，方案数相同，为 dp[i-j][j]
        // 所以，dp[i][j] = dp[i-1][j-1] + dp[i-j][j]
        // 初始 dp[0][0] = 1，空方案
        // 若 i > j，dp[i][j] = 0
        const int MOD = 1e9 + 7;
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                if (i >= j) {
                    dp[i][j] = (dp[i - 1][j - 1] + dp[i - j][j]) % MOD;
                }
            }
        }
        return dp[n][k];
    }
};