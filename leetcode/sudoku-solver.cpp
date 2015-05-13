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
        const int M = (int)board.size();
        const int N = (int)board[0].size();
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (board[i][j] == '.') {
                    for (char c = '1'; c <= '9'; ++c) {
                        board[i][j] = c;
                        if (isValid(i, j, board) && solve(board)) return true;
                    }
                    board[i][j] = '.';
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isValid(int x, int y, const vector<vector<char>> &board) {
        if (board.empty()) return false;
        const int M = (int)board.size();
        const int N = (int)board[0].size();
        // 检查行
        for (int i = 0; i < N; ++i) {
            if (i != y && board[x][i] == board[x][y]) return false;
        }
        // 检查列
        for (int i = 0; i < M; ++i) {
            if (i != x && board[i][y] == board[x][y]) return false;
        }
        // 检查小格
        for (int startI = x / 3 * 3, i = startI; i < startI + 3; ++i) {
            for (int startJ = y / 3 * 3, j = startJ; j < startJ + 3; ++j) {
                if ((i != x || j != y) && board[i][j] == board[x][y]) return false;
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
