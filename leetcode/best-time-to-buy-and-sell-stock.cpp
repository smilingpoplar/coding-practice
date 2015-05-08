//
//  best-time-to-buy-and-sell-stock
//  https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
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
        // 若在第i天卖，应在[0,i)天中最便宜时买
        if (prices.size() < 2) return 0;
        int bestProfit = 0;
        int minPrice = prices[0];
        for (auto i = 1; i < prices.size(); i++) {
            bestProfit = max(bestProfit, prices[i] - minPrice);
            minPrice = min(minPrice, prices[i]);
        }
        return bestProfit;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> prices = {4, 2, 9};
    Solution solution;
    cout << solution.maxProfit(prices);
    
    return 0;
}
