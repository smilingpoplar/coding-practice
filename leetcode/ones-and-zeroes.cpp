//
//  ones-and-zeroes
//  https://leetcode.com/problems/ones-and-zeroes/
//
//  Created by smilingpoplar on 17/11/26.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    // 01背包问题，两维代价m和n
    // 设dp[k][i][j]表示前k个串、剩余i个0和j个1时可得的最大数
    // dp[k][i][j] = max{ dp[k-1][i][j], 1 + dp[k-1][i-(0s)_k][j-(1s)_k] /*选不选第k个串*/ }
    // dp[k][][]只依赖dp[k-1][][]，降维
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (const auto &str: strs) {
            int zeros = 0, ones = 0;
            for (char c : str) {
                if (c == '0') zeros++;
                else ones++;
            }
            // 01背包，从右往左遍历代价
            for (int i = m; i >= zeros; i--) {
                for (int j = n; j >= ones; j--) {
                    dp[i][j] = max( dp[i][j], 1 + dp[i - zeros][j - ones] );
                }
            }
        }
        return dp[m][n];
    }
};


int main(int argc, const char * argv[]) {    
    return 0;
}
