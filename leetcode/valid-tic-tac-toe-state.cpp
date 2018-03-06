//
//  valid-tic-tac-toe-state
//  https://leetcode.com/problems/valid-tic-tac-toe-state/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int xCount = 0, oCount = 0;
        for (auto &row : board) {
            for (char c : row) {
                if (c == 'X') xCount++;
                else if (c == 'O') oCount++;
            }
        }
        
        if (xCount != oCount + 1 && xCount != oCount) return false;
        if (hasRowOf('X', board) && xCount != oCount + 1) return false;
        if (hasRowOf('O', board) && xCount != oCount) return false;
        return true;
    }
    
    // 检查行、列、对角线是否全是c
    bool hasRowOf(char c, vector<string>& board) {
        for (int i = 0; i < 3; i++) {
            if (c == board[i][0] && c == board[i][1] && c == board[i][2]) return true;
            if (c == board[0][i] && c == board[1][i] && c == board[2][i]) return true;
        }
        if (c == board[0][0] && c == board[1][1] && c == board[2][2]) return true;
        if (c == board[0][2] && c == board[1][1] && c == board[2][0]) return true;            
        return false;
    }

};

int main(int argc, const char * argv[]) {
    return 0;
}
