//
//  coin-change
//  https://leetcode.com/problems/coin-change/
//
//  Copyright (c) 2017年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // 完全背包问题：选最少的硬币数使面值总和为amount
        const int theMax = amount + 1;
        vector<int> dp(amount + 1, theMax);
        dp[0] = 0;
        for (int coin : coins) {
            for (int i = coin; i <= amount; i++) { // 正序遍历各容量
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
        return (dp[amount] != theMax) ? dp[amount] : -1;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
