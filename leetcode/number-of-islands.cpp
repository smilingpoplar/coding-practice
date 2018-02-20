//
//  number-of-islands
//  https://leetcode.com/problems/number-of-islands/
//
//  Created by smilingpoplar on 15/5/2.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        const size_t M = grid.size();
        const size_t N = grid[0].size();
        vector<vector<bool>> visited(M, vector<bool>(N, false));
        
        int count = 0;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    count++;
                    dfs(i, j, grid, visited);
                }
            }
        }
        return count;
    }

    void dfs(int i, int j, const vector<vector<char>> &grid, vector<vector<bool>> &visited) {
        const size_t M = grid.size();
        const size_t N = grid[0].size();
        if (i < 0 || i >= M || j < 0 || j >= N 
            || grid[i][j] == '0' || visited[i][j]) return;
        visited[i][j] = true;
        dfs(i - 1, j, grid, visited);
        dfs(i + 1, j, grid, visited);
        dfs(i, j - 1, grid, visited);
        dfs(i, j + 1, grid, visited);
    }
};

int main(int argc, const char * argv[]) {
    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'},
    };
    Solution solution;
    cout << solution.numIslands(grid);
    
    return 0;
}
