//
//  range-sum-query-2d-immutable
//  https://leetcode.com/problems/range-sum-query-2d-immutable/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class NumMatrix {
    vector<vector<int>> sum;
    int R, C;
public:
    NumMatrix(vector<vector<int>> matrix) {
        if (matrix.empty()) return;
        R = matrix.size();
        C = matrix[0].size();
        sum = vector<vector<int>>(R, vector<int>(C, 0));
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                int value = matrix[r][c];
                if (r > 0) value += sum[r-1][c];
                if (c > 0) value += sum[r][c-1];
                if (r > 0 && c > 0) value -= sum[r-1][c-1];
                sum[r][c] = value;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if (!(0 <= row1 && row1 <= row2 && row2 < R 
              && 0 <= col1 && col1 <= col2 && col2 < C)) return 0;
        int ans = sum[row2][col2];
        if (row1 > 0) ans -= sum[row1-1][col2];
        if (col1 > 0) ans -= sum[row2][col1-1];
        if (row1 > 0 && col1 > 0) ans += sum[row1-1][col1-1];
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */

int main(int argc, const char * argv[]) {    
    return 0;
}
