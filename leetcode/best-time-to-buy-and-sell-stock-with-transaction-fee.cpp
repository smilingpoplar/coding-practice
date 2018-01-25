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
        // 设dp[i][0]表示第i天手上没股票、dp[i][1]表示第i天手上有1股股票时的最大利润
        // dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i] /*第i天卖股票*/)
        // dp[i][1] = max(dp[i-1][1], dp[i-1][0]-prices[i]-fee /*第i天买股票*/)
        // 初始dp[-1][0]=0，dp[-1][1]=INT_MIN
        // 因为dp[i][]只依赖dp[i-1][]，降一维。令share0=dp[0], share1=dp[1]
        int share0 = 0;
        int share1 = INT_MIN;
        for (int i = 0; i < prices.size(); i++) {
            int oldShare0 = share0;
            share0 = max(share0, share1 + prices[i]); // fee放到下面买时扣，避免share1下溢出
            share1 = max(share1, oldShare0 - prices[i] - fee);
        }
        return share0;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
