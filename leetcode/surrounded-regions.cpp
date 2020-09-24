//
//  surrounded-regions
//  https://leetcode.com/problems/surrounded-regions/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        // 只有边缘的0不会被填充，先找这些0
        if (board.empty()) return;
        const int R = board.size(), C = board[0].size();
        
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(R, vector<bool>(C, false));
        // 四条边进队
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (r == 0 || r == R - 1 || c == 0 || c == C - 1) {
                    q.push({r, c});
                    visited[r][c] = true;
                }
            }
        }
        // 找边缘的0
        const vector<vector<int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        vector<vector<bool>> zeros(R, vector<bool>(C, false));
        while (!q.empty()) {
            auto curr = q.front(); q.pop();
            int r = curr.first, c = curr.second;
            if (board[r][c] == 'X') continue;
            
            zeros[r][c] = true;
            for (auto &dir : dirs) {
                int nr = r + dir[0], nc = c + dir[1];
                if (nr < 0 || nr >= R || nc < 0 || nc >= C || visited[nr][nc]) continue;
                q.push({nr, nc});
                visited[nr][nc] = true;
            }
        }
        
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
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
