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
        for (int r = 0; r < M; r++) {
            for (int c = 0; c < N; c++) {
                if (r == 0 || r == M - 1 || c == 0 || c == N - 1) {
                    q.push({r, c});
                    visited[r][c] = true;
                }
            }
        }
        while (!q.empty()) {
            auto curr = q.front(); q.pop();
            int r = curr.first, c = curr.second;
            if (board[r][c] == 'X') continue;
            
            zeros[r][c] = true;
            vector<pair<int,int>> nexts = {{r - 1, c}, {r + 1, c}, {r, c - 1}, {r, c + 1}};
            for (auto &next : nexts) {
                int nr = next.first, nc = next.second;
                if (nr < 0 || nr >= M || nc < 0 || nc >= N || visited[nr][nc]) continue;
                q.push(next);
                visited[nr][nc] = true;
            }
        }
        
        for (int r = 0; r < M; r++) {
            for (int c = 0; c < N; c++) {
                if (!zeros[r][c]) board[r][c] = 'X';
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