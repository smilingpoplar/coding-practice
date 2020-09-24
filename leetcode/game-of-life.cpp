//
//  game-of-life
//  https://leetcode.com/problems/game-of-life/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        // inplace：board[r][c]用第0位表示当前状态，第1位表示下一状态
        if (board.empty()) return;
        const int R = board.size(), C = board[0].size();
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                int lives = liveNeighbors(board, r, c);
                if (board[r][c] & 1) { // a live cell
                    if (2 <= lives && lives <= 3) board[r][c] |= 2;
                } else {
                    if (lives == 3) board[r][c] |= 2;
                } 
            }
        }
        
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                board[r][c] >>= 1;
            }
        }
    }
    
    int liveNeighbors(vector<vector<int>> &board, int r, int c) {
        int minR = max(0, r-1), maxR = min((int)board.size()-1, r+1);
        int minC = max(0, c-1), maxC = min((int)board[0].size()-1, c+1);
        int lives = 0;
        for (int i = minR; i <= maxR; i++) {
            for (int j = minC; j <= maxC; j++) {
                lives += board[i][j] & 1;
            }
        }
        lives -= board[r][c] & 1;
        return lives;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
