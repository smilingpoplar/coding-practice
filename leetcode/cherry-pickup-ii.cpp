//
//  cherry-pickup-ii
//  https://leetcode.com/problems/cherry-pickup-ii/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        // 两机器人同时走r步到(r,c1), (r,c2)
        const int R = grid.size(), C = grid[0].size();
        vector<vector<vector<int>>> memo(R, vector<vector<int>>(C, vector<int>(C, -1)));
        return dfs(0, 0, C - 1, grid, memo);
    }

    int dfs(int r, int c1, int c2, vector<vector<int>> &grid,
            vector<vector<vector<int>>> &memo) {
        const int R = grid.size(), C = grid[0].size();
        if (memo[r][c1][c2] != -1) return memo[r][c1][c2];

        int ans = 0;
        for (int d1 = -1; d1 <= 1; d1++) {
            for (int d2 = -1; d2 <= 1; d2++) {
                int nc1 = c1 + d1, nc2 = c2 + d2;
                if (r + 1 >= R || nc1 < 0 || nc1 >= C || nc2 < 0 || nc2 >= C) continue;
                ans = max(ans, dfs(r + 1, nc1, nc2, grid, memo));
            }
        }

        int pick = (c1 == c2) ? grid[r][c1] : grid[r][c1] + grid[r][c2];
        ans += pick;
        return memo[r][c1][c2] = memo[r][c2][c1] = ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
