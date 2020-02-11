//
//  largest-1-bordered-square
//  https://leetcode.com/problems/largest-1-bordered-square/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        const int R = grid.size(), C = grid[0].size();
        // 辅助矩阵统计grid[i][j]往右、往下连续1的个数
        vector<vector<int>> right(R, vector<int>(C, 0));
        vector<vector<int>> down(R, vector<int>(C, 0));
        for (int r = R - 1; r >= 0; r--) {
            for (int c = C - 1; c >= 0; c--) {
                if (grid[r][c]) {
                    right[r][c] = (c + 1 < C) ? right[r][c+1] + 1 : 1;
                    down[r][c] = (r + 1 < R) ? down[r+1][c] + 1 : 1;
                }
            }
        }
        
        int maxLen = 0;
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                for (int len = min(right[r][c], down[r][c]); len > maxLen; len--) {
                    // 检查len是否可行
                    if (right[r+len-1][c] >= len && down[r][c+len-1] >= len) {
                        maxLen = len;
                        break;
                    }
                }
            }
        }
        return maxLen * maxLen;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
