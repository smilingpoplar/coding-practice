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
        const int M = matrix.size();
        const int N = matrix[0].size();
        vector<vector<int>> memo(M, vector<int>(N, 0));
        int ans = 0;
        for (int r = 0; r < M; r++) {
            for (int c = 0; c < N; c++) {
                ans = max(ans, dfs(matrix, r, c, memo));
            }
        }
        return ans;
    }
    
    int dfs(vector<vector<int>>& matrix, int r, int c, vector<vector<int>>& memo) {
        const int M = matrix.size();
        const int N = matrix[0].size();
        if (!isValidIndex(r, c, M, N)) return 0;
        if (memo[r][c] > 0) return memo[r][c];
        
        vector<vector<int>> dirs = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
        int expand = 0;
        for (auto &d : dirs) {
            int nr = r + d[0], nc = c + d[1];
            if (isValidIndex(nr, nc, M, N) && matrix[nr][nc] > matrix[r][c]) {
                expand = max(expand, dfs(matrix, nr, nc, memo));
            }
        }
        memo[r][c] = 1 + expand;
        return memo[r][c];
    }
    
    bool isValidIndex(int r, int c, int M, int N) {
        return 0 <= r && r < M && 0 <= c && c < N;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
