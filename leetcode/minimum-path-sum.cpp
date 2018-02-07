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
        // 设dp[i][j]表示从左上角到grid[i][j]的最小路径和，0<=i<M，0<=j<N
        // 可以往右往下走，dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j]
        if (grid.empty()) return 0;
        const int M = grid.size();
        const int N = grid[0].size();
        vector<vector<int>> dp(M, vector<int>(N, 0));
        dp[0][0] = grid[0][0];
        for (int i = 1; i < M; i++) 
            dp[i][0] = dp[i-1][0] + grid[i][0];
        for (int j = 1; j < N; j++)
            dp[0][j] = dp[0][j-1] + grid[0][j];
        for (int i = 1; i < M; i++) {
            for (int j = 1; j < N; j++) {
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }
        return dp[M-1][N-1];
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
