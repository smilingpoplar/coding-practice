//
//  candy-crush
//  https://leetcode.com/problems/candy-crush/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        // 先整体扫描出可消除的点，标记为负值，再整体消除标记点
        // 从上到下、从左到右扫描，这样每个点只要往下往右查三格，不用再往上往左查
        if (board.empty()) return {};
        const int R = board.size();
        const int C = board[0].size();
        
        while (true) {
            // 标记
            bool found = false;
            for (int r = 0; r < R; r++) {
                for (int c = 0; c < C; c++) {
                    int v = abs(board[r][c]);
                    if (v == 0) continue;
                    // 往下查三格
                    if (r + 2 < R && v == abs(board[r+1][c]) && v == abs(board[r+2][c])) {
                        found = true;
                        board[r][c] = board[r+1][c] = board[r+2][c] = -v;
                    }
                    // 往右查三格
                    if (c + 2 < C && v == abs(board[r][c+1]) && v == abs(board[r][c+2])) {
                        found = true;
                        board[r][c] = board[r][c+1] = board[r][c+2] = -v;
                    }
                }
            }
            if (!found) break;
            
            // 消除
            for (int c = 0; c < C; c++) {
                int write = R - 1;
                for (int r = R - 1; r >= 0; r--) {
                    if (board[r][c] > 0) 
                        board[write--][c] = board[r][c];
                }
                while (write >= 0) {
                    board[write--][c] = 0;
                }
            }
        }
        return board;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
