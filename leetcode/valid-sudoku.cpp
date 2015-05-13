//
//  valid-sudoku
//  https://leetcode.com/problems/valid-sudoku/
//
//  Created by smilingpoplar on 15/5/13.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if (board.empty()) return true;
        const int M = (int)board.size();
        const int N = (int)board[0].size();
        
        vector<bool> used(9, false); // 数[1,9]是否被用过
        // 检查行
        for (int i = 0; i < M; ++i) {
            fill(used.begin(), used.end(), false);
            for (int j = 0; j < N; ++j) {
                if (!isValid(board[i][j], used)) return false;
            }
        }
        // 检查列
        for (int j = 0; j < N; ++j) {
            fill(used.begin(), used.end(), false);
            for (int i = 0; i < M; ++i) {
                if (!isValid(board[i][j], used)) return false;
            }
        }
        // 检查小格
        for (int startI = 0; startI < M; startI += 3) {
            for (int startJ = 0; startJ < N; startJ += 3) {
                fill(used.begin(), used.end(), false);
                for (int i = startI; i < startI + 3; ++i) {
                    for (int j = startJ; j < startJ + 3; ++j) {
                        if (!isValid(board[i][j], used)) return false;
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
