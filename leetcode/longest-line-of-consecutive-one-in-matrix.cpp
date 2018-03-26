//
//  longest-line-of-consecutive-one-in-matrix
//  https://leetcode.com/problems/longest-line-of-consecutive-one-in-matrix/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        // dp[i][j][0]表示到(i,j)为止该行     连续1的个数，
        // dp[i][j][1]               列
        // dp[i][j][2]               对角线
        // dp[i][j][3]               反对角线
        if (M.empty()) return 0;
        const int R = M.size();
        const int C = M[0].size();
        vector<vector<vector<int>>> dp(R, vector<vector<int>>(C, vector<int>(4, 0)));
        
        int ans = 0;
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (M[r][c] == 1) {
                    dp[r][c][0] = (c > 0) ? (dp[r][c-1][0] + 1) : 1;
                    dp[r][c][1] = (r > 0) ? (dp[r-1][c][1] + 1) : 1;
                    dp[r][c][2] = (r > 0 && c > 0) ? (dp[r-1][c-1][2] + 1) : 1;
                    dp[r][c][3] = (r > 0 && c + 1 < C) ? (dp[r-1][c+1][3] + 1) : 1;
                    ans = max({ans, dp[r][c][0], dp[r][c][1], dp[r][c][2], dp[r][c][3]});
                }
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
