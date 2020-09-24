//
//  profitable-schemes
//  https://leetcode.com/problems/profitable-schemes/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int profitableSchemes(int G, int P, vector<int>& group, vector<int>& profit) {
        // 设dp[i][g][p]表示前i个案件、g人至少p利润时的方案数
        // dp[i][g][p] = dp[i-1][g][p] + dp[i-1][g-group[i]][max(0, p-profit[i])] )
        // 当p-profit[i]为负时要求“至少负利润”，这是都能达到的，等价于“至少0利润”，所以用max(0, p-profit[i])
        // 初始dp[0][0][0] = 1
        // 省掉i这维，i仍从左往右遍历。01背包问题，两维代价，逆序遍历
        const int MOD = 1e9 + 7;
        const int N = group.size();
        vector<vector<int>> dp(G + 1, vector<int>(P + 1, 0));
        dp[0][0] = 1;
        for (int i = 0; i < N; i++) {
            for (int g = G; g >= group[i]; g--) {
                for (int p = P; p >= 0; p--) {
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
