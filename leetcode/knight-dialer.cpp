//
//  knight-dialer
//  https://leetcode.com/problems/knight-dialer/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int knightDialer(int N) {
        const int MOD = 1e9 + 7;
        // 各数字可以跳到哪些数字
        vector<vector<int>> jump = {
            {4, 6}, {6, 8}, {7, 9}, {4, 8}, {0, 3, 9},
            {}, {0, 1, 7}, {2, 6}, {1, 3}, {2, 4}
        };
        // 动态规划，设dp[i][d]表示i个数以数字d结尾的号码数，
        // dp[i][dst] = sum(dp[i-1][src])
        // i只依赖前一项，省掉i这维，ndp[dst] = sum(dp[src])
        vector<long> dp(10, 1);
        for (int i = 1; i < N; i++) { // 跳N-1次
            vector<long> ndp(10, 0);
            for (int d = 0; d < 10; d++) {
                for (int nd : jump[d]) {
                    ndp[nd] = (ndp[nd] + dp[d]) % MOD;
                }
            }
            swap(ndp, dp);
        }
        long ans = 0;
        for (int i = 0; i < 10; i++) {
            ans = (ans + dp[i]) % MOD;
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
