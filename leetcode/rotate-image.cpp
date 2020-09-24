//
//  rotate-image
//  https://leetcode.com/problems/rotate-image/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // 旋转90度跟"转置"有关
        // 顺时针旋转90度 <=等价=> 先转置、再把行反转
        // 1 2 3      1 4 7      7 4 1 
        // 4 5 6  =>  2 5 8  =>  8 5 2
        // 7 8 9      3 6 9      9 6 3
        const int N = matrix.size();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (auto &row : matrix) {
            reverse(row.begin(), row.end());
        }
    }
};

/*
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // 顺时针旋转90度<=等价=>先转置、再把行反转，(r,c)=>(c,N-1-r)
        // 置换组：(r,c) => (c,N-1-r) => (N-1-r,N-1-c) => (N-1-c,r) => (r,c)
        // 取上一半的倒三角形的1/4矩阵进行置换
        if (matrix.empty()) return;
        const int N = matrix.size();
        for (int r = 0; r < N / 2; r++) {
            for (int c = r; c < N - 1 - r; c++) {
                int tmp = matrix[r][c];
                matrix[r][c] = matrix[N-1-c][r];
                matrix[N-1-c][r] = matrix[N-1-r][N-1-c];
                matrix[N-1-r][N-1-c] = matrix[c][N-1-r];
                matrix[c][N-1-r] = tmp;
            }
        }
    }
};
*/

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
