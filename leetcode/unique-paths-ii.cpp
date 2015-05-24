//
//  unique-paths-ii
//  https://leetcode.com/problems/unique-paths-ii/
//
//  Created by smilingpoplar on 15/5/24.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        const int M = (int)grid.size();
        const int N = (int)grid[0].size();
        vector<vector<int>> f(M, vector<int>(N, 0));
        // 设f(i,j)表示从[0,0]到[i,j]的路径数，0<=i<=M-1，0<=j<=N-1
        // 可往右往下走，f(i,j) = grid[i,j] ? 0 : f(i-1,j) + f(i,j-1)
        f[0][0] = grid[0][0] ? 0 : 1;
        for (int i = 1; i <= M - 1; ++i) {
            f[i][0] = grid[i][0] ? 0 : f[i - 1][0];
        }
        for (int j = 1; j <= N - 1; ++j) {
            f[0][j] = grid[0][j] ? 0 : f[0][j - 1];
        }
        for (int i = 1; i <= M - 1; ++i) {
            for (int j = 1; j <= N - 1; ++j) {
                f[i][j] = grid[i][j] ? 0 : f[i - 1][j] + f[i][j - 1];
            }
        }
        return f[M - 1][N - 1];
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
