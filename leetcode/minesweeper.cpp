//
//  minesweeper
//  https://leetcode.com/problems/minesweeper/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if (board.empty()) return board;
        
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        dfs(board, click[0], click[1], visited);
        return board;
    }
    
    void dfs(vector<vector<char>>& board, int r, int c, vector<vector<bool>> &visited) {
        if (board.empty()) return;
        const int R = board.size(), C = board[0].size();
        if (!isValidIndex(r, c, R, C) || visited[r][c]) return;
        visited[r][c] = true;
        
        if (board[r][c] == 'M') {
            board[r][c] = 'X';
            return;
        }
        vector<vector<int>> dirs = { {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, 
                                    {1, 1}, {1, 0}, {1, -1}, {0, -1} };
        int mines = 0;
        for (auto &d : dirs) {
            int nr = r + d[0], nc = c + d[1];
            if (isValidIndex(nr, nc, R, C) && board[nr][nc] == 'M') mines++;
        }
        if (mines > 0) {
            board[r][c] = '0' + mines;
            return;
        }
        board[r][c] = 'B';
        for (auto &d : dirs) {
            dfs(board, r + d[0], c + d[1], visited);
        }
    }
    
    bool isValidIndex(int r, int c, int R, int C) {
        return 0 <= r && r < R && 0 <= c && c < C;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
