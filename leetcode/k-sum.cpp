//
//  k-sum
//  https://www.lintcode.com/problem/k-sum/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int kSum(vector<int> &A, int K, int target) {
        // 设dp[i][k][t]表示前i个数中选k个数，它们的和为t的方式数
        // dp[i][k][t] = dp[i-1][k][t] /*不选num*/ + dp[i-1][k-1][t-num] /*选num*/
        // 二维费用的01背包问题；可省掉i这维，i仍从左往右遍历，k和t逆序遍历
        const int N = A.size();
        vector<vector<int>> dp(K + 1, vector<int>(target + 1, 0));
        dp[0][0] = 1;

        for (int num : A) {
            for (int k = K; k >= 1; k--) {
                for (int t = target; t >= num; t--) {
                    dp[k][t] += dp[k-1][t-num];
                }
            }
        }
        return dp[K][target];
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
