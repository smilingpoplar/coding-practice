//
//  range-sum-query-2d-mutable
//  https://leetcode.com/problems/range-sum-query-2d-mutable/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

/*
class NumMatrix {
    int M, N;
    vector<vector<int>> _matrix;
    // 2D二叉索引树，tree[i][j]保存子矩阵(i-i&-i, i], (j-j&-j, j]的和
    vector<vector<int>> tree;
public:
    NumMatrix(vector<vector<int>> matrix) {
        if (matrix.empty()) return;
        M = matrix.size();
        N = matrix[0].size();
        _matrix = vector<vector<int>>(M, vector<int>(N, 0));
        tree = vector<vector<int>>(M + 1, vector<int>(N + 1, 0));
        for (int r = 0; r < M; r++) {
            for (int c = 0; c < N; c++) {
                update(r, c, matrix[r][c]);
            }
        }
    }
    
    void update(int row, int col, int val) {
        if (M == 0 || N == 0) return;
        int delta = val - _matrix[row][col];
        _matrix[row][col] = val;
        for (int r = row + 1; r <= M; r += r & -r) {
            for (int c = col + 1; c <= N; c += c & -c) {
                tree[r][c] += delta;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if (M == 0 || N == 0) return 0;
        return getSum(row2, col2) - getSum(row1 - 1, col2) 
            - getSum(row2, col1 - 1) + getSum(row1 - 1, col1 - 1);
    }
    
    int getSum(int row, int col) {
        int sum = 0;
        for (int r = row + 1; r > 0; r -= r & -r) {
            for (int c = col + 1; c > 0; c -= c & -c) {
                sum += tree[r][c];
            }
        }
        return sum;
    }
};
*/

class NumMatrix {
    vector<vector<int>> _matrix;
    vector<vector<int>> colSums; // colSums[r][c]表示第c列前r行的和
public:
    NumMatrix(vector<vector<int>> matrix) : _matrix(matrix) {
        if (matrix.empty()) return;
        const int M = matrix.size();
        const int N = matrix[0].size();
        colSums = vector<vector<int>>(M + 1, vector<int>(N, 0));
        for (int c = 0; c < N; c++) {
            for (int r = 1; r <= M; r++) {
                colSums[r][c] = colSums[r-1][c] + matrix[r-1][c];
            }
        }
    }
    
    void update(int row, int col, int val) {
        int delta = val - _matrix[row][col];
        _matrix[row][col] = val;
        for (int r = row + 1; r <= _matrix.size(); r++) {
            colSums[r][col] += delta;
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for (int c = col1; c <= col2; c++) {
            sum += colSums[row2+1][c] - colSums[row1][c];
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * obj.update(row,col,val);
 * int param_2 = obj.sumRegion(row1,col1,row2,col2);
 */

int main(int argc, const char * argv[]) {
    return 0;
}
