//
//  paint-house
//  https://leetcode.com/problems/paint-house/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        // 设dp[i][j]表示到房子i漆上色j的最小代价，有dp[i][j]=min(dp[i-1][k])+cost[i][j], k!=j
        // 递推式i这维只依赖于i-1项，去掉i这维，i仍从左往右遍历。j这维依赖方向不确定，要使用临时变量newdp[]。
        // dp[j]=min(dp[k])+cost[i][j], k!=j。初始dp[j]=cost[0][j]。
        if (costs.empty()) return 0;
        const int N = costs.size(), C = costs[0].size();
        vector<int> dp = costs[0];
        for (int i = 1; i < N; i++) {
            vector<int> newdp(C);
            for (int j = 0; j < C; j++) {
                newdp[j] = min(dp[(j+1) % C], dp[(j+2) % C]) + costs[i][j];
            }
            swap(newdp, dp);
        }
        return *min_element(dp.begin(), dp.end());
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
