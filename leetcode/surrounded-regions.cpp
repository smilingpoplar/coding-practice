//
//  surrounded-regions
//  https://leetcode.com/problems/surrounded-regions/
//
//  Created by smilingpoplar on 15/6/18.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        // 只有边缘的0不会被填充，找到这些0
        // 递归dfs会导致栈溢出，可用迭代写法，就这题来说，用bfs更好（全是0的最坏情况，dfs占n^2空间，bfs占4n空间）
        if (board.empty()) return;
        const int M = (int)board.size();
        const int N = (int)board[0].size();
        
        vector<vector<bool>> zeros(M, vector<bool>(N, false));
        vector<vector<bool>> visited(M, vector<bool>(N, false));
        queue<pair<int, int>> q;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (i == 0 || i == M - 1 || j == 0 || j == N - 1) {
                    q.push({i, j});
                }
            }
        }
        while (!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            if (i < 0 || i >= M || j < 0 || j >= N || visited[i][j]) continue;
            visited[i][j] = true;
            if (board[i][j] == 'X') continue;
            
            zeros[i][j] = true;
            if (i - 1 >= 0) q.push({i - 1, j});
            if (i + 1 < M) q.push({i + 1, j});
            if (j - 1 >= 0) q.push({i, j - 1});
            if (j + 1 < N) q.push({i, j + 1});
        }
        
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (!zeros[i][j]) board[i][j] = 'X';
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    vector<vector<char>> board = {
        {'X','X','X','X'},
        {'X','0','0','X'},
        {'X','X','0','X'},
        {'X','X','X','X'},
        {'X','0','X','X'},
    };
    
    Solution solution;
    solution.solve(board);
    for (const auto &row : board) {
        for (auto cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}