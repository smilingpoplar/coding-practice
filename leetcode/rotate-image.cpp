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
        // 矩阵旋转90度的问题先转置再观察，观察知应转置后再把行反转，(i,j)=>(j,N-1-i)
        // 置换组：(i,j) => (j,N-1-i) => (N-1-i,N-1-j) => (N-1-j,i) => (i,j)
        // 取倒三角形的1/4矩阵进行置换
        if (matrix.empty()) return;
        const int M = (int)matrix.size();
        const int N = (int)matrix[0].size();
        for (int i = 0; i < M / 2; ++i) {
            for (int j = i; j < N - 1 - i; ++j) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[N - 1 - j][i];
                matrix[N - 1 - j][i] = matrix[N - 1 - i][N - 1 - j];
                matrix[N - 1 - i][N - 1 - j] = matrix[j][N - 1 - i];
                matrix[j][N - 1 - i] = temp;
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
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[0].size(); ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
