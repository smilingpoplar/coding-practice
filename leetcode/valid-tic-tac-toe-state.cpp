//
//  valid-tic-tac-toe-state
//  https://leetcode.com/problems/valid-tic-tac-toe-state/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int xCnt = 0, oCnt = 0;
        for (auto &row : board) {
            for (char c : row) {
                if (c == 'X') xCnt++;
                else if (c == 'O') oCnt++;
            }
        }
        
        if (xCnt != oCnt + 1 && xCnt != oCnt) return false;
        if (hasRowOf('X', board) && xCnt != oCnt + 1) return false;
        if (hasRowOf('O', board) && xCnt != oCnt) return false;
        return true;
    }
    
    // 检查行、列、对角线是否有一个全是c
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
