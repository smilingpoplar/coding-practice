//
//  paint-house-ii
//  https://leetcode.com/problems/paint-house-ii/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        // dp的维度对应dfs的递归参数
        // 设dp[i][c]表示前[0..i]房子、第i房颜色为c时的minCost
        // dp[i][c] = min{ dp[i-1][not_c] } + costs[i][c]，初始dp[0][c] = costs[0][c]
        // 而求min{ dp[i-1][not_c] }，只要维护dp[i-1][]对应的最小min1、第i-1房的颜色min1c、以及第二小min2，
        // 这样 min{ dp[i-1][not_c] } = (c != min1c ? min1 : min2)
        // dp[i][c] = (c != min1c ? min1 : min2) + costs[i][c]
        // 所求为dp[N-1][]中的最小min1
        if (costs.empty()) return 0;
        const int N = costs.size(), K = costs[0].size();
        int min1 = 0, min1c = -1, min2 = 0;
        for (int i = 0; i < N; i++) {
            int tmp_min1 = INT_MAX, tmp_min1c = -1, tmp_min2 = INT_MAX; // dp[i][]对应的一组值
            for (int c = 0; c < K; c++) {
                int cost = (c != min1c ? min1 : min2) + costs[i][c];
                if (cost < tmp_min1) {
                    tmp_min2 = tmp_min1;
                    tmp_min1 = cost;
                    tmp_min1c = c;
                } else if (cost < tmp_min2) {
                    tmp_min2 = cost;
                }
            }
            min1 = tmp_min1, min1c = tmp_min1c, min2 = tmp_min2;
        }
        return min1;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
