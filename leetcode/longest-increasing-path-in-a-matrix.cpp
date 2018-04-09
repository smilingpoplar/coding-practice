//
//  longest-increasing-path-in-a-matrix
//  https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 0;
        const int R = matrix.size();
        const int C = matrix[0].size();
        vector<vector<int>> memo(R, vector<int>(C, 0));
        int ans = 0;
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                ans = max(ans, dfs(matrix, r, c, memo));
            }
        }
        return ans;
    }
    
    int dfs(vector<vector<int>>& matrix, int r, int c, vector<vector<int>>& memo) {
        const int R = matrix.size();
        const int C = matrix[0].size();
        if (!isValidIndex(r, c, R, C)) return 0;
        if (memo[r][c] > 0) return memo[r][c];
        
        vector<vector<int>> dirs = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
        int expand = 0;
        for (auto &d : dirs) {
            int nr = r + d[0], nc = c + d[1];
            if (isValidIndex(nr, nc, R, C) && matrix[nr][nc] > matrix[r][c]) {
                expand = max(expand, dfs(matrix, nr, nc, memo));
            }
        }
        memo[r][c] = 1 + expand;
        return memo[r][c];
    }
    
    bool isValidIndex(int r, int c, int R, int C) {
        return 0 <= r && r < R && 0 <= c && c < C;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
