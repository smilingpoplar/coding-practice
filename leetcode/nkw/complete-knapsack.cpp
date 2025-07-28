//
//  complete-knapsack
//  NC309 完全背包
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> knapsack(int v, int n, vector<vector<int> >& nums) {
        int ans1;
        {
            // 不用恰好装满
            vector<int> dp(v + 1, 0);
            for (vector<int>& vw : nums) {
                int vi = vw[0], wi = vw[1];
                for (int i = vi; i <= v; i++) {
                    dp[i] = max(dp[i], dp[i - vi] + wi);
                }
            }
            ans1 = INT_MIN;
            for (int i = 0; i <= v; i++) {
                ans1 = max(ans1, dp[i]);
            }
        }

        int ans2;
        {
            // 恰好装满
            vector<int> dp(v + 1, INT_MIN);
            dp[0] = 0;
            for (vector<int>& vw : nums) {
                int vi = vw[0], wi = vw[1];
                for (int i = vi; i <= v; i++) {
                    dp[i] = max(dp[i], dp[i - vi] + wi);
                }
            }
            ans2 = dp[v] < 0 ? 0 : dp[v];
        }

        return {ans1, ans2};
    }
};