//
//  maximal-square
//  https://leetcode.com/problems/maximal-square/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        // 设dp[i][j]表示i行j列、右下角为[i-1,j-1]的子矩阵能构成的最大方形边长
        // matrix[i-1][j-1]==1时，dp[i][j] = min( dp[i-1][j], dp[i][j-1], dp[i-1][j-1] /*即左、上、左上格*/) + 1
        // 初始dp[0][0]=0
        if (matrix.empty()) return 0;
        const int M = matrix.size();
        const int N = matrix[0].size();
        vector<vector<int>> dp(M + 1, vector<int>(N + 1, 0));
        int maxlen = 0;
        for (int i = 1; i <= M; i++) {
            for (int j = 1; j <= N; j++) {
                if (matrix[i-1][j-1] == '1') {
                    dp[i][j] = min({ dp[i-1][j-1], dp[i-1][j], dp[i][j-1] }) + 1;
                    maxlen = max(maxlen, dp[i][j]);
                }
            }
        }
        return maxlen * maxlen;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
