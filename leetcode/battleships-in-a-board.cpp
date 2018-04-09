//
//  battleships-in-a-board
//  https://leetcode.com/problems/battleships-in-a-board/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        // 因为这里的非连通子图形状特殊，只要找出每个子图的左上角，就能数出子图的个数
        if (board.empty()) return 0;
        const int R = board.size();
        const int C = board[0].size();
        int count = 0;
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (board[r][c] == '.') continue;
                if (r > 0 && board[r-1][c] == 'X') continue;
                if (c > 0 && board[r][c-1] == 'X') continue;
                ++count;
            }
        }
        return count;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
