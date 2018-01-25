//
//  best-time-to-buy-and-sell-stock-iv
//  https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
//
//  Created by smilingpoplar on 15/5/9.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        const int N = (int)prices.size();
        if (k == 0 || N < 2) return 0;
        // k足够大时，相当于对交易次数无限制
        if (k >= N/2) return maxProfitInfK(prices);
        
        // 设dp[i][j][s]表示第i天、剩余交易数j、手上s股股票时的最大利润，s=0或1
        // dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1] + prices[i] /*卖股票*/)
        // dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0] - prices[i] /*买股票，新交易*/)
        // 初始dp[-1][j][0]=0，dp[-1][j][1]=INT_MIN
        // dp[i][][]只依赖dp[i-1][][]，降一维
        vector<vector<int>> dp(k + 1, vector<int>({ 0, INT_MIN }));
        for (int price : prices) {
            for (int j = k; j >= 1; j--) { // 倒序，这样等号右边的dp[j-1][]来自旧状态[i-1]
                dp[j][0] = max(dp[j][0], dp[j][1] + price);
                dp[j][1] = max(dp[j][1], dp[j-1][0] - price);
            }
        }
        return dp[k][0];
    }
    
    int maxProfitInfK(vector<int>& prices) {
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

int main(int argc, const char * argv[]) {
    vector<int> prices = {3,2,6,5,0,3};
    Solution solution;
    cout << solution.maxProfit(2, prices);
    
    return 0;
}
