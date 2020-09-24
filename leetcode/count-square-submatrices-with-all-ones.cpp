//
//  count-square-submatrices-with-all-ones
//  https://leetcode.com/problems/count-square-submatrices-with-all-ones/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.`
//

#include <iostream>

using namespace std;

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        // 设dp[i][j]表示右下角在[i-1,j-1]的最大正方形子矩阵边长。
        // 当matrix[i-1][j-1]==1时，
        // dp[i][j] = 1 /*右下角的'1'*/ + min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) /*即左、上、左上矩阵*/
        // 初始dp[0][..]=dp[..][0]=0
        if (matrix.empty()) return 0;
        const int M = matrix.size(), N = matrix[0].size();
        vector<vector<int>> dp(M + 1, vector<int>(N + 1, 0));
        int ans = 0;
        for (int i = 1; i <= M; i++) {
            for (int j = 1; j <= N; j++) {
                if (matrix[i-1][j-1] == 1) {
                    dp[i][j] = 1 + min({ dp[i-1][j-1], dp[i-1][j], dp[i][j-1] });
                }
                ans += dp[i][j];
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
