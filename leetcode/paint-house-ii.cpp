//
//  paint-house-ii
//  https://leetcode.com/problems/paint-house-ii/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        // dp的维度来自dfs中的递归参数
        // 设dp[i][c]表示前[0..i]房子、第i房颜色为c时的minCost
        // dp[i][c] = costs[i][c] + min{ dp[i-1][not_c] }，初始dp[0][c] = costs[0][c]
        // 而求min{ dp[i-1][not_c] }，只需要维护dp[i-1][]中的最小min1（及其对应的颜色min1c）和第二小min2
        // 这样，dp[i][c] = costs[i][c] + (min1c != c ? min1 : min2)
        if (costs.empty()) return 0;
        const int N = costs.size();
        const int K = costs[0].size();
        int min1 = 0, min1c = -1, min2 = 0;
        for (int i = 0; i < N; i++) {
            int currMin1 = INT_MAX, currMin1c = -1, currMin2 = INT_MAX;
            for (int c = 0; c < K; c++) {
                int cost = costs[i][c] + (min1c != c ? min1 : min2);
                if (cost < currMin1) {
                    currMin2 = currMin1;
                    currMin1 = cost;
                    currMin1c = c;
                } else if (cost < currMin2) {
                    currMin2 = cost;
                }
            }
            min1 = currMin1, min1c = currMin1c, min2 = currMin2;
        }
        return min1;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
