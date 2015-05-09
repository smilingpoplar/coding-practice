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
        // 特例：当k>=N/2时，相当于对交易次数无限制，变成问题ii，只要在价格上升阶段买入卖出即可
        if (k >= N / 2) return maxProfitInf(prices);
        
        // 最多买卖k次，动态规划，在第i天可买和卖，用两个变量分别记录买和卖后的最大利润
        // 用buy(i,j)表示prices[0,i]最多买j次后的最大利润，sell(i,j)表示prices[0,i]最多卖j次后的最大利润 (0<=i<N, 0<=j<=k)
        // buy(i,j) = max( sell(i-1,j-1)-prices[i] /*第i天买*/, buy(i-1,j) /*第i天不买*/ )
        // sell(i,j) = max( buy(i-1,j)+prices[i] /*第i天卖*/, sell(i-1,j) /*第i天不卖*/ )
        // i==0时，初值：buy(0,j)=-prices[0]/*最多买一次*/，sell(0,j)=0/*还没买无法卖*/
        // 因为上述递推式中第i天的buy和sell只跟第i-1天的值有关，按i循环时可降维
        // buy(j) = max( sell(j-1)-prices(i), buy(j) )
        // sell(j) = max( buy(j)+prices[i], sell(j) )
        vector<int> buy(k + 1, -prices[0]);
        vector<int> sell(k + 1, 0);
        for (int i = 0; i < N; i++) { // 按i递增循环
            for (int j = 1; j <= k; j++) {
                buy[j] = max(sell[j - 1] - prices[i], buy[j]);
                sell[j] = max(buy[j] + prices[i], sell[j]);
            }
        }
        return sell[k];
    }
private:
    int maxProfitInf(vector<int>& prices) {
        int maxProfit = 0;
        for (int i = 0; i < (int)prices.size() - 1; i++) {
            if (prices[i + 1] > prices[i]) {
                maxProfit += prices[i + 1] - prices[i];
            }
        }
        return maxProfit;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> prices = {3,2,6,5,0,3};
    Solution solution;
    cout << solution.maxProfit(2, prices);
    
    return 0;
}
