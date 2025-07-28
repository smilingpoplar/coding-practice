//
//  rectangle-coverage
//  NC268 矩形覆盖
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rectCover(int n) {
        // dp[i] = dp[i-1] + dp[i-2]
        // 初始 dp[0] = 0, dp[1] = 1, dp[2] = 2;
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};