//
//  best-time-to-buy-and-sell-stock-ii
//  https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
//
//  Created by smilingpoplar on 15/5/9.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

/*
class Solution {
public:    
    int maxProfit(vector<int>& prices) {
        // 设dp[i][s]表示第i天、手上有s股股票时的最大利润，s=0或1
        // dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i] /*卖股票*/)
        // dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i] /*买股票*/)
        // 初始dp[-1][0]=0，dp[-1][1]=INT_MIN
        // dp[i][]只依赖dp[i-1][]，降维
        int share0 = 0;
        int share1 = INT_MIN;
        for (int price : prices) {
            int oldShare0 = share0;
            share0 = max(share0, share1 + price);
            share1 = max(share1, oldShare0 - price);
        }
        return share0;
    }
};
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 可以无限次购买，相隔两数有利可图就购买
        if (prices.size() < 2) return 0;
        int maxProfit = 0;
        for (auto i = 0; i < prices.size() - 1; i++) {
            if (prices[i] < prices[i + 1]) {
                maxProfit += prices[i + 1] - prices[i];
            }
        }
        return maxProfit;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> prices = {4, 2, 9, 8, 7, 5, 8};
    Solution solution;
    cout << solution.maxProfit(prices);
    
    return 0;
}
