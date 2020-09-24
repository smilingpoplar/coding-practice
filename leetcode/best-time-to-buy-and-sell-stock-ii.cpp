//
//  best-time-to-buy-and-sell-stock-ii
//  https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

/*
class Solution {
public:    
    int maxProfit(vector<int>& prices) {
        // 设dp[i][s]表示第i天、手上有s=0或1股股票时的最大利润
        // dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i] /*卖股票*/)
        // dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i] /*买股票*/)
        // 初始dp[-1][0]=0，dp[-1][1]=INT_MIN（不合法）
        // dp在i这维上只依赖i-1项，去掉i这维
        vector<int> dp = { 0, INT_MIN };
        for (int price : prices) {
            int dp0 = dp[0];
            dp[0] = max(dp0, dp[1] + price);
            dp[1] = max(dp[1], dp0 - price);
        }
        return dp[0];
    }
};
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 可以无限次购买，相隔两数有利可图就购买
        const int N = prices.size();
        int ans = 0;
        for (auto i = 0; i < N - 1; i++) {
            if (prices[i] < prices[i+1]) {
                ans += prices[i+1] - prices[i];
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> prices = {4, 2, 9, 8, 7, 5, 8};
    Solution solution;
    cout << solution.maxProfit(prices);
    
    return 0;
}
