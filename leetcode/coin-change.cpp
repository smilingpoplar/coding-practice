//
//  coin-change
//  https://leetcode.com/problems/coin-change/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // 完全背包问题：选最少的硬币数使面值总和为amount
        const int THE_MAX = amount + 1;
        vector<int> dp(amount + 1, THE_MAX);
        dp[0] = 0;
        for (int c : coins) {
            for (int v = c; v <= amount; v++) { // 正序遍历各容量
                dp[v] = min(dp[v], dp[v-c] + 1);
            }
        }
        return (dp[amount] != THE_MAX) ? dp[amount] : -1;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
