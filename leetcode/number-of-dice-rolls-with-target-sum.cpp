//
//  number-of-dice-rolls-with-target-sum
//  https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int numRollsToTarget(int D, int F, int target) {
        // 题目：取D次数，每次在[1..F]，总和为target
        // 设dp[d][t]表示取d次数、总和为t的子问题解
        // dp[d][t] = sum( dp[d-1][t-f] ), f为[1..F]
        // 初始dp[0][0]=1，dp[>0][0]=0，dp[0][>0]=0
        // 第d项只依赖d-1项，省掉d这维，用临时变量ndp[]，d从左往右遍历
        // ndp[t] = sum( dp[t-f] )
        // 带分组的01背包问题
        const int MOD = 1e9 + 7;
        vector<int> dp(target + 1);
        dp[0] = 1; // dp[0][0]=0

        for (int d = 1; d <= D; d++) {
            vector<int> ndp(target + 1); // dp[>0][0]=0
            for (int t = 1; t <= target; t++) {
                for (int f = 1; f <= F; f++) {
                    if (t - f >= 0) ndp[t] = (ndp[t] + dp[t-f]) % MOD;
                }
            }
            swap(dp, ndp);
        }
        return dp[target];
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
