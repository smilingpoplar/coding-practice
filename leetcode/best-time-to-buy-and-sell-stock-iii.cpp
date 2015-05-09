//
//  best-time-to-buy-and-sell-stock-iii
//  https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
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
        // 最多买卖两次，可以把prices[0,N-1]分成prices[0,i]和prices[i,N-1]分别求maxProfix (1<=i<N)
        const int N = (int)prices.size();
        if (N < 2) return 0;
        // maxProfit[0,i]
        vector<int> maxProfitLeft(N, 0);
        int minPrice = prices[0];
        for (int i = 1; i < N; i++) {
            maxProfitLeft[i] = max(maxProfitLeft[i - 1], prices[i] - minPrice);
            minPrice = min(minPrice, prices[i]);
        }
        // maxProfit[i,N-1]
        vector<int> maxProfitRight(N, 0);
        int maxPrice = prices[N - 1];
        for (int i = N - 2; i >= 0; i--) {
            maxProfitRight[i] = max(maxProfitRight[i + 1], maxPrice - prices[i]);
            maxPrice = max(maxPrice, prices[i]);
        }
        // maxProfix[0,N-1]
        int maxProfit = 0;
        for (int i = 1; i < N; i++) {
            maxProfit = max(maxProfit, maxProfitLeft[i] + maxProfitRight[i]);
        }
        return maxProfit;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> prices = {1,2,3,2,1,2};
    Solution solution;
    cout << solution.maxProfit(prices);
    
    return 0;
}
