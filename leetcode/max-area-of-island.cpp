//
//  max-area-of-island
//  https://leetcode.com/problems/max-area-of-island/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        const int R = grid.size(), C = grid[0].size();
        vector<vector<bool>> visited(R, vector<bool>(C, false));

        int ans = 0;
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                ans = max(ans, area(r, c, grid, visited));
            }
        }
        return ans;
    }
    
    int area(int r, int c, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() 
            || visited[r][c] || grid[r][c] == 0) return 0;

        visited[r][c] = true;
        return 1 + area(r - 1, c, grid, visited) + area(r + 1, c, grid, visited) 
            + area(r, c - 1, grid, visited) + area(r, c + 1, grid, visited);
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
