//
//  set-matrix-zeroes
//  https://leetcode.com/problems/set-matrix-zeroes/
//
//  Created by smilingpoplar on 15/6/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // 用第0行记录某一列是否有0，用第0列记录某一行是否有0
        if (matrix.empty()) return;
        const int R = matrix.size(), C = matrix[0].size();

        bool zeroInRow0 = false;
        for (int c = 0; c < C; c++) {
            if (matrix[0][c] == 0) {
                zeroInRow0 = true;
                break;
            }
        }
        bool zeroInCol0 = false;
        for (int r = 0; r < R; r++) {
            if (matrix[r][0] == 0) {
                zeroInCol0 = true;
                break;
            }
        }
        
        for (int r = 1; r < R; r++) {
            for (int c = 1; c < C; c++) {
                if (matrix[r][c] == 0) {
                    matrix[r][0] = 0;
                    matrix[0][c] = 0;
                }
            }
        }
        // 清零
        for (int r = 1; r < R; r++) {
            for (int c = 1; c < C; c++) {
                if (matrix[0][c] == 0 || matrix[r][0] == 0) {
                    matrix[r][c] = 0;
                }
            }
        }
        if (zeroInRow0) {
            for (int c = 0; c < C; c++) {
                matrix[0][c] = 0;
            }
        }
        if (zeroInCol0) {
            for (int r = 0; r < R; r++) {
                matrix[r][0] = 0;
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    vector<vector<int>> matrix = {
        {1,1,1,0,1},
        {1,1,1,1,1},
        {1,0,1,1,1},
        {1,1,0,1,1},
        {1,1,1,1,1},
    };
    Solution solution;
    solution.setZeroes(matrix);
    
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
