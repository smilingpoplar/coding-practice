//
//  cut-rope
//  NC281 剪绳子
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int cutRope(int n) {
        // 设dp[i]表示绳子总长为i时最大乘积
        // dp[i] = max{ j * (i-j), j * dp[i-j] }, 0 < j < i
        // 初始 dp[1] = 0
        vector<int> dp(n + 1, INT_MIN);
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                dp[i] = max({dp[i], j * (i - j), j * dp[i - j]});
            }
        }
        return dp[n];
    }
};