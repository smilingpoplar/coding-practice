//
//  game-of-life
//  https://leetcode.com/problems/game-of-life/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        // board[r][c]用第0位表示当前状态，第1位表示下一状态
        if (board.empty()) return;
        const int M = board.size();
        const int N = board[0].size();
        for (int r = 0; r < M; r++) {
            for (int c = 0; c < N; c++) {
                int lives = liveNeighbors(board, r, c);
                if (board[r][c] & 1) {
                    if (2 <= lives && lives <= 3) board[r][c] |= 2;
                } else {
                    if (lives == 3) board[r][c] |= 2;
                } 
            }
        }
        
        for (int r = 0; r < M; r++) {
            for (int c = 0; c < N; c++) {
                board[r][c] >>= 1;
            }
        }
    }
    
    int liveNeighbors(vector<vector<int>> &board, int r, int c) {
        int lives = 0;
        int leftI = max(0, r-1), rightI = min((int)board.size()-1, r+1);
        int leftJ = max(0, c-1), rightJ = min((int)board[0].size()-1, c+1);
        for (int i = leftI; i <= rightI; i++) {
            for (int j = leftJ; j <= rightJ; j++) {
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
