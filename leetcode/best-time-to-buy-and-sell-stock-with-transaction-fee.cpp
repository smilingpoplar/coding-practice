//
//  best-time-to-buy-and-sell-stock-with-transaction-fee
//  https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        // 设dp[i][s]表示第i天、手上有s=0或1股股票时的最大利润
        // dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i] /*卖股票*/)
        // dp[i][1] = max(dp[i-1][1], dp[i-1][0]-prices[i]-fee /*买股票*/)
        // 初始dp[-1][0]=0，dp[-1][1]=INT_MIN
        // dp[i][]只依赖dp[i-1][]，去掉i这维
        vector<int> dp = { 0, INT_MIN };
        for (int price : prices) {
            int dp0 = dp[0];
            dp[0] = max(dp0, dp[1] + price);
            dp[1] = max(dp[1], dp0 - price - fee);
        }
        return dp[0];
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
