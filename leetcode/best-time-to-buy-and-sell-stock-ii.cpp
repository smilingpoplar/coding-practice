//
//  best-time-to-buy-and-sell-stock-ii
//  https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
//
//  Created by smilingpoplar on 15/5/9.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 可以买卖多次，那么在价格上升时买入后卖出
        if (prices.size() < 2) return 0;
        int bestProfit = 0;
        for (auto i = 0; i < prices.size() - 1; i++) {
            if (prices[i] < prices[i + 1]) {
                bestProfit += prices[i + 1] - prices[i];
            }
        }
        return bestProfit;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> prices = {4, 2, 9, 8, 7, 5, 8};
    Solution solution;
    cout << solution.maxProfit(prices);
    
    return 0;
}
