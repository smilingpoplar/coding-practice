//
//  paint-house
//  https://leetcode.com/problems/paint-house/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        // 设dp[i][c]表示前[0..i]房子、第i房颜色为c时的最小代价
        // 有dp[i][c]=min(dp[i-1][not_c])+costs[i][c]
        // 初始dp[0][c]=costs[0][c]
        // 递推式在i维上只依赖i-1项，省掉i这维，i仍从左往右遍历
        // c这维的依赖方向不确定，要用临时变量ndp[]
        // ndp[c]=min(dp[not_c])+costs[i][c]
        if (costs.empty()) return 0;
        const int N = costs.size(), C = costs[0].size();
        vector<int> dp = costs[0];
        for (int i = 1; i < N; i++) {
            vector<int> ndp(C);
            for (int c = 0; c < C; c++) {
                ndp[c] = min(dp[(c+1) % C], dp[(c+2) % C]) + costs[i][c];
            }
            swap(dp, ndp);
        }
        return min({dp[0], dp[1],dp[2]});
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
