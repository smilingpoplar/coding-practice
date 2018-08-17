//
//  profitable-schemes
//  https://leetcode.com/problems/profitable-schemes/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int profitableSchemes(int G, int P, vector<int>& group, vector<int>& profit) {
        // 设dp[i][g][p]表示前i个案件、g人至少p利润时的方案数
        // dp[i][g][p] = dp[i-1][g][p] + dp[i-1][g-group[i]][max(0, p-profit[i])] )
        // max(0, p-profit[i])作下标表示**至少**p利润
        // 初始dp[0][0][0] = 1
        // 省掉i这维，i仍从左往右遍历
        // 01背包问题，两维代价，逆序遍历
        const int MOD = 1e9 + 7;
        const int N = group.size();
        vector<vector<int>> dp(G + 1, vector<int>(P + 1, 0));
        dp[0][0] = 1;
        for (int i = 0; i < N; i++) { // 遍历案件
            for (int g = G; g >= group[i]; g--) { // 保证 g-group[i] >= 0
                for (int p = P; p >= 0; p--) { // 保证 max(0, p-profit[i]) >= 0
                    dp[g][p] = (dp[g][p] + dp[g - group[i]][max(0, p - profit[i])]) % MOD;
                }
            }
        }
        
        int ans = 0;
        for (int g = 0; g <= G; g++) {
            ans = (ans + dp[g][P]) % MOD;
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
