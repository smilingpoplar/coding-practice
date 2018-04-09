//
//  pacific-atlantic-water-flow
//  https://leetcode.com/problems/pacific-atlantic-water-flow/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        // 分别dfs看访问的点有哪些重叠
        if (matrix.empty()) return {};
        const int R = matrix.size();
        const int C = matrix[0].size();
        vector<vector<bool>> pacific(R, vector<bool>(C, false));
        vector<vector<bool>> atlantic(R, vector<bool>(C, false));

        for (int c = 0; c < C; c++) {
            dfs(matrix, pacific, 0, c, INT_MIN);
            dfs(matrix, atlantic, R - 1, c, INT_MIN);
        }
        for (int r = 0; r < R; r++) {
            dfs(matrix, pacific, r, 0, INT_MIN);
            dfs(matrix, atlantic, r, C - 1, INT_MIN);
        }
        
        vector<pair<int, int>> ans;
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (pacific[r][c] && atlantic[r][c]) 
                    ans.push_back({r, c});
            }
        }
        return ans;
    }
    
    void dfs(vector<vector<int>>& matrix, vector<vector<bool>> &visited,
             int r, int c, int prevHeight) {
        const int R = matrix.size();
        const int C = matrix[0].size();
        if (!(0 <= r && r < R && 0 <= c && c < C) 
            || visited[r][c] || matrix[r][c] < prevHeight) return;
        visited[r][c] = true;
        vector<vector<int>> dirs = { {-1,0}, {0,1}, {1,0}, {0,-1} };
        for (auto &dir : dirs) {
            int nr = r + dir[0], nc = c + dir[1];
            dfs(matrix, visited, nr, nc, matrix[r][c]);
        }
    }    
};

int main(int argc, const char * argv[]) {
    return 0;
}
