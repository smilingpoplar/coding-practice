//
//  minimum-path-sum
//  https://leetcode.com/problems/minimum-path-sum/
//
//  Created by smilingpoplar on 15/5/26.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        // 设dp[r][c]表示从左上角到grid[r][c]的最小路径和，0<=r<R，0<=c<C
        // 可以往右往下走，dp[r][c] = min(dp[r-1][c], dp[r][c-1]) + grid[r][c]
        if (grid.empty()) return 0;
        const int R = grid.size();
        const int C = grid[0].size();
        vector<vector<int>> dp(R, vector<int>(C, 0));
        dp[0][0] = grid[0][0];
        for (int r = 1; r < R; r++) 
            dp[r][0] = dp[r-1][0] + grid[r][0];
        for (int c = 1; c < C; c++)
            dp[0][c] = dp[0][c-1] + grid[0][c];
        for (int r = 1; r < R; r++) {
            for (int c = 1; c < C; c++) {
                dp[r][c] = min(dp[r-1][c], dp[r][c-1]) + grid[r][c];
            }
        }
        return dp[R-1][C-1];
    }
};

int main(int argc, const char * argv[]) {
    vector<vector<int>> grid = {
        {1,1,1},
        {1,2,1},
        {1,2,1},
    };
    Solution solution;
    cout << solution.minPathSum(grid);
    
    return 0;
}
