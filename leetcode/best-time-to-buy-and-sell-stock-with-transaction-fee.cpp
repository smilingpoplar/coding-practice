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
        // 设dp[i][0]表示第i天手上没股票、dp[i][1]表示第i天手上有1股票的剩余现金
        // dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i] /*第i天卖股票*/), i=[1..n]
        // dp[i][1] = max(dp[i-1][1], dp[i-1][0]-prices[i]-fee /*第i天买股票*/), i=[1..n]
        // 初始dp[0][0]=0，dp[0][1]=INT_MIN，INT_MIN表示非法状态
        // 因为dp[i][]只依赖dp[i-1][]，降一维，只剩两变量noshare=dp[0], holdshare=dp[1]
        int noshare = 0;
        int holdshare = INT_MIN;
        for (int i = 0; i < prices.size(); ++i) {
            int tmpNoshare = max(noshare, holdshare + prices[i]);
            holdshare = max(holdshare, noshare - prices[i] - fee);
            noshare = tmpNoshare;
        }
        return noshare;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
