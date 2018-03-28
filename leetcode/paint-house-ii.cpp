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
        // 设dp[i][c]表示前[0..i]个房子、第i房子颜色c时的minCost
        // dp[i][c] = costs[i][c] + min{ dp[i-1][not_c] }
        // 初始dp[0][c] = costs[0][c]
        // dp[i][]只依赖于dp[i-1][]，去掉i维度降维，设curr[]表示dp[i][]，prev[]表示dp[i-1][]
        if (costs.empty()) return 0;
        const int N = costs.size();
        const int K = costs[0].size();
        vector<int> prev = costs[0];
        for (int i = 1; i < N; i++) {
            vector<int> curr(K, INT_MAX);
            for (int c = 0; c < K; c++) {
                for (int not_c = 0; not_c < K; not_c++) {
                    if (not_c != c) {
                        curr[c] = min(curr[c], costs[i][c] + prev[not_c]);                
                    }
                }
            }
            swap(curr, prev);
        }
        return *min_element(prev.begin(), prev.end());
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
