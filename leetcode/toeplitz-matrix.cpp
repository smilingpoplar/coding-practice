//
//  toeplitz-matrix
//  https://leetcode.com/problems/toeplitz-matrix/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        const int R = matrix.size(), C = matrix[0].size();
        // 两点在同一主对角线上，满足r1-c1=r2-c2
        unordered_map<int, int> diag; // r1-c1值相等的对角线上的值
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (!diag.count(r - c)) {
                    diag[r-c] = matrix[r][c];
                } else if (diag[r-c] != matrix[r][c]) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
