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
        if (prices.size() < 2) return 0;
        // 只能买卖一次，若在第i天卖，应在[0,i)天最便宜时买
        int ans = 0;
        int minPrice = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            ans = max(ans, prices[i] - minPrice);
            minPrice = min(minPrice, prices[i]);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> prices = {4, 2, 9};
    Solution solution;
    cout << solution.maxProfit(prices);
    
    return 0;
}
