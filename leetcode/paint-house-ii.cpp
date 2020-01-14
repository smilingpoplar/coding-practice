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
        // dp[i][c] = min{ dp[i-1][not_c] } + costs[i][c]，初始dp[0][c] = costs[0][c]
        // 而求min{ dp[i-1][not_c] }，只要维护dp[i-1][]中的最小min1、此时的c值min1c（c!=min1c时取min1）、
        // 以及第二小min2，这样 min{ dp[i-1][not_c] } = (c != min1c ? min1 : min2)
        // dp[i][c] = (c != min1c ? min1 : min2) + costs[i][c]
        // 所求为dp[N-1][]中的最小min1
        if (costs.empty()) return 0;
        const int N = costs.size(), K = costs[0].size();
        int min1 = 0, min1c = -1, min2 = 0; // 对应dp[i-1][]的一组值
        for (int i = 0; i < N; i++) {
            int min1_i = INT_MAX, min1c_i = -1, min2_i = INT_MAX; // 对应dp[i][]的一组值
            for (int c = 0; c < K; c++) {
                int cost = (c != min1c ? min1 : min2) + costs[i][c];
                if (cost < min1_i) {
                    min2_i = min1_i;
                    min1_i = cost;
                    min1c_i = c;
                } else if (cost < min2_i) {
                    min2_i = cost;
                }
            }
            min1 = min1_i, min1c = min1c_i, min2 = min2_i;
        }
        return min1;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
