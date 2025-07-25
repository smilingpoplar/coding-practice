//
//  number-of-binary-tree
//

#include <iostream>

using namespace std;

class Solution {
public:
    int numberOfTree(int n) {
        if (n <= 1) return n;
        // 设dp[m]表示节点个数为m时的树形数
        // dp[m] =  sum{ dp[i] * dp[m-1-i] }, 0<=i<m, m > 1
        vector<long> dp(n + 1, 0);
        dp[0] = dp[1] = 1;
        const int MOD = 1e9 + 7;
        for (int m = 2; m <= n; m++) {
            for (int i = 0; i < m; i++) {
                dp[m] = (dp[m] + dp[i] * dp[m - 1 - i]) % MOD;
            }
        }
        return dp[n];
    }
};