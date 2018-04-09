//
//  rotate-image
//  https://leetcode.com/problems/rotate-image/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // 矩阵旋转90度的问题先转置再观察，观察知应转置后再把行反转，(r,c)=>(c,C-1-r)
        // 置换组：(r,c) => (c,C-1-r) => (C-1-r,C-1-c) => (C-1-c,r) => (r,c)
        // 取倒三角形的1/4矩阵进行置换
        if (matrix.empty()) return;
        const int R = matrix.size();
        const int C = matrix[0].size();
        for (int r = 0; r < R / 2; r++) {
            for (int c = r; c < C - 1 - r; c++) {
                int tmp = matrix[r][c];
                matrix[r][c] = matrix[C - 1 - c][r];
                matrix[C - 1 - c][r] = matrix[C - 1 - r][C - 1 - c];
                matrix[C - 1 - r][C - 1 - c] = matrix[c][C - 1 - r];
                matrix[c][C - 1 - r] = tmp;
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };
    
    Solution solution;
    solution.rotate(matrix);
    for (int r = 0; r < matrix.size(); r++) {
        for (int c = 0; c < matrix[0].size(); c++) {
            cout << matrix[r][c] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
