//
//  number-of-islands
//  https://leetcode.com/problems/number-of-islands/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        const int R = grid.size(), C = grid[0].size();
        vector<vector<bool>> visited(R, vector<bool>(C, false));
        
        int count = 0;
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (grid[r][c] == '1' && !visited[r][c]) {
                    count++;
                    dfs(r, c, grid, visited);
                }
            }
        }
        return count;
    }

    void dfs(int r, int c, const vector<vector<char>> &grid, vector<vector<bool>> &visited) {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size()
            || grid[r][c] == '0' || visited[r][c]) return;
        visited[r][c] = true;
        dfs(r - 1, c, grid, visited);
        dfs(r + 1, c, grid, visited);
        dfs(r, c - 1, grid, visited);
        dfs(r, c + 1, grid, visited);
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
