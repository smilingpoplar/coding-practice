//
//  best-time-to-buy-and-sell-stock-with-cooldown
//  https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 设dp[i][0]表示第i天、手中无股票时的最大利润，设dp[i][1]表示第i天、手中1股股票时的最大利润
        // dp[i][0]=max(dp[i-1][0], dp[i-1][1]+prices[i] /*卖股票*/)
        // dp[i][1]=max(dp[i-1][1], dp[i-2][0]-prices[i] /*买股票*/)
        // 初始dp[-1][0]=0，dp[-1][1]=INT_MIN；dp[-2][0]=0，dp[-2][1]=INT_MIN
        // dp[i][]只依赖dp[i-1][]、dp[i-2][]
        vector<int> prev2 = { 0, INT_MIN };
        vector<int> prev1 = { 0, INT_MIN };
        for (int i = 0; i < prices.size(); i++) {
            vector<int> cur(2);
            cur[0] = max(prev1[0], prev1[1] + prices[i]);
            cur[1] = max(prev1[1], prev2[0] - prices[i]);
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1[0];
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
