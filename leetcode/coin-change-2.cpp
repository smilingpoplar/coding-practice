//
//  coin-change-2
//  https://leetcode.com/problems/coin-change-2/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // 完全背包问题
        // 设dp[i][v]表示coins[0..i]凑出面值v的方式数
        // dp[i][v] = dp[i-1][v] + dp[i][v-coins[i]]
        // 初始dp[-1][0]=1
        // 省掉i这维，i仍从左往右遍历；dp[v] += dp[v-coins[i]]，v从左往右遍历
        const int N = coins.size();
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (int coin : coins) {
            for (int v = coin; v <= amount; v++) { // 正序遍历
                dp[v] += dp[v - coin];
            }
        }
        return dp[amount];
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
