//
//  design-tic-tac-toe
//  https://leetcode.com/problems/design-tic-tac-toe/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class TicTacToe {
    // 统计各行、各列、各对角线的(X数-O数)
    vector<int> rowCnt;
    vector<int> colCnt;
    int diagCnt = 0;
    int antiDiagCnt = 0;
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) : rowCnt(n, 0), colCnt(n, 0) {
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        const int n = rowCnt.size();
        int delta = (player == 1) ? 1 : -1;
        rowCnt[row] += delta;
        colCnt[col] += delta;
        if (row == col) diagCnt += delta;
        if (row + col == n - 1) antiDiagCnt += delta;

        if (abs(rowCnt[row]) == n ||
            abs(colCnt[col]) == n ||
            abs(diagCnt) == n ||
            abs(antiDiagCnt) == n) {
            return player;
        }
        return 0;            
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */

int main(int argc, const char * argv[]) {
    return 0;
}
