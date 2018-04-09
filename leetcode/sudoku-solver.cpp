//
//  sudoku-solver
//  https://leetcode.com/problems/sudoku-solver/
//
//  Created by smilingpoplar on 15/5/13.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        if (board.empty()) return;
        solve(board);
    }
private:
    bool solve(vector<vector<char>> &board) {
        // 尝试填空格，然后测试是否合法
        const int R = board.size();
        const int C = board[0].size();
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (board[r][c] == '.') {
                    for (char ch = '1'; ch <= '9'; ch++) {
                        board[r][c] = ch;
                        if (isValid(r, c, board) && solve(board)) return true;
                    }
                    board[r][c] = '.';
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isValid(int row, int col, const vector<vector<char>> &board) {
        if (board.empty()) return false;
        const int R = board.size();
        const int C = board[0].size();
        // 检查行
        for (int c = 0; c < C; c++) {
            if (c != col && board[row][c] == board[row][col]) return false;
        }
        // 检查列
        for (int r = 0; r < R; r++) {
            if (r != row && board[r][col] == board[row][col]) return false;
        }
        // 检查小格
        for (int startR = row / 3 * 3, r = startR; r < startR + 3; r++) {
            for (int startC = col / 3 * 3, c = startC; c < startC + 3; c++) {
                if ((r != row || c != col) && board[r][c] == board[row][col]) return false;
            }
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'},
    };
    
    Solution solution;
    solution.solveSudoku(board);
    for (const auto &row : board) {
        for (char c : row) {
            cout << c;
        }
        cout << endl;
    }
    
    return 0;
}
