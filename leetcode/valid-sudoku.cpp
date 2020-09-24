//
//  valid-sudoku
//  https://leetcode.com/problems/valid-sudoku/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if (board.empty()) return true;
        const int R = board.size();
        const int C = board[0].size();
        
        vector<bool> used(9, false); // 数[1,9]是否被用过
        // 检查行
        for (int r = 0; r < R; r++) {
            fill(used.begin(), used.end(), false);
            for (int c = 0; c < C; c++) {
                if (!isValid(board[r][c], used)) return false;
            }
        }
        // 检查列
        for (int c = 0; c < C; c++) {
            fill(used.begin(), used.end(), false);
            for (int r = 0; r < R; r++) {
                if (!isValid(board[r][c], used)) return false;
            }
        }
        // 检查小格
        for (int startR = 0; startR < R; startR += 3) {
            for (int startC = 0; startC < C; startC += 3) {
                fill(used.begin(), used.end(), false);
                for (int r = startR; r < startR + 3; r++) {
                    for (int c = startC; c < startC + 3; c++) {
                        if (!isValid(board[r][c], used)) return false;
                    }
                }
            }
        }
        return true;
    }
private:
    bool isValid(char c, vector<bool> &used) {
        if (c == '.') return true;
        if (used[c - '1']) return false;
        used[c - '1'] = true;
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
    cout << solution.isValidSudoku(board);
    
    return 0;
}
