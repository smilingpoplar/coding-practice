//
//  circle-go-zero
//  NC311 圆环回原点
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int circle(int n) {
        // 设dp[i][j]表示走i步到j点的方式数，0<=i<=n, 0<=j<=9
        // dp[i][j] = dp[i-1][(j-1+len)%len] + dp[i-1][(j+1)%len]
        const int MOD = 1e9 + 7;
        vector<vector<int>> dp(n + 1, vector<int>(10, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= 9; j++) {
                dp[i][j] = (dp[i - 1][(j - 1 + 10) % 10] + dp[i - 1][(j + 1) % 10]) % MOD;
            }
        }
        return dp[n][0];
    }
};