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
    int M, N;
public:
    NumMatrix(vector<vector<int>> matrix) {
        if (matrix.empty()) return;
        M = matrix.size();
        N = matrix[0].size();
        sum = vector<vector<int>>(M, vector<int>(N, 0));
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                int value = matrix[i][j];
                if (i > 0) value += sum[i-1][j];
                if (j > 0) value += sum[i][j-1];
                if (i > 0 && j > 0) value -= sum[i-1][j-1];
                sum[i][j] = value;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if (!(0 <= row1 && row1 <= row2 && row2 < M 
              && 0 <= col1 && col1 <= col2 && col2 < N)) return 0;
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
