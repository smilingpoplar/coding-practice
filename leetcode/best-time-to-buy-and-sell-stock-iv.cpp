//
//  best-time-to-buy-and-sell-stock-iv
//  https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        const int N = prices.size();
        if (k == 0 || N < 2) return 0;
        // k足够大时，相当于对交易次数无限制
        if (k >= N/2) return maxProfitInfK(prices);
        
        // 设dp[i][j][s]表示第i天、至多交易了j次、手上有s=0或1股股票时的最大利润
        // dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1] + prices[i] /*卖股票*/)
        // dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0] - prices[i] /*买股票，新交易*/)
        // 初始dp[-1][j][0]=0，dp[-1][j][1]=INT_MIN
        // dp在i这维上只依赖于i-1项，去掉i这维
        // 降维后，要让dp[j-1][]表示旧状态，j要从右往左遍历
        vector<vector<int>> dp(k + 1, vector<int>({ 0, INT_MIN }));
        for (int price : prices) {
            for (int j = k; j >= 1; j--) {
                dp[j][0] = max(dp[j][0], dp[j][1] + price);
                dp[j][1] = max(dp[j][1], dp[j-1][0] - price);
            }
        }
        return dp[k][0];
    }

    int maxProfitInfK(vector<int>& prices) {
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
    vector<int> prices = {3,2,6,5,0,3};
    Solution solution;
    cout << solution.maxProfit(2, prices);
    
    return 0;
}
