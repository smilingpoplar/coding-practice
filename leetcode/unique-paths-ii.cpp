//
//  unique-paths-ii
//  https://leetcode.com/problems/unique-paths-ii/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        const int R = grid.size(), C = grid[0].size();
        vector<vector<int>> dp(R, vector<int>(C, 0));
        // 设dp(r,c)表示从[0,0]到[r,c]的路径数，0<=r<R，0<=c<C
        // 可往右往下走，dp(r,c) = grid[r,c] ? 0 : dp(r-1,c) + dp(r,c-1)
        dp[0][0] = grid[0][0] ? 0 : 1;
        for (int r = 1; r < R; r++) {
            dp[r][0] = grid[r][0] ? 0 : dp[r-1][0];
        }
        for (int c = 1; c < C; c++) {
            dp[0][c] = grid[0][c] ? 0 : dp[0][c-1];
        }
        for (int r = 1; r < R; r++) {
            for (int c = 1; c < C; c++) {
                dp[r][c] = grid[r][c] ? 0 : dp[r-1][c] + dp[r][c-1];
            }
        }
        return dp[R-1][C-1];
    }
};

int main(int argc, const char * argv[]) {
    vector<vector<int>> grid = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0},
    };
    Solution solution;
    cout << solution.uniquePathsWithObstacles(grid);
    
    return 0;
}
