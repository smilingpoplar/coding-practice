//
//  best-time-to-buy-and-sell-stock-iii
//  https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int N = prices.size();
        if (N < 2) return 0;     
        // 设dp[i][j][s]表示第i天、至多交易了j次、手上有s=0或1股股票时的最大利润
        // dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1] + prices[i] /*卖股票*/)
        // dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0] - prices[i] /*买股票，新交易*/)
        // 初始dp[-1][..][0]=0，dp[-1][..][1]=INT_MIN
        // dp在i这维上只依赖于i-1项，去掉i这维
        // 降维后，要让dp[j-1][]表示旧状态，j要从右往左遍历
        const int k = 2;
        vector<vector<int>> dp(k + 1, vector<int>({ 0, INT_MIN }));
        for (int price : prices) {
            for (int j = k; j >= 1; j--) {
                dp[j][0] = max(dp[j][0], dp[j][1] + price);
                dp[j][1] = max(dp[j][1], dp[j-1][0] - price);
            }
        }
        return dp[k][0];
    }
};

int main(int argc, const char * argv[]) {
    vector<int> prices = {1,2,3,2,1,2};
    Solution solution;
    cout << solution.maxProfit(prices);
    
    return 0;
}
