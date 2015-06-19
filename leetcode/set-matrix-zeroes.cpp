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
        const int M = (int)matrix.size();
        const int N = (int)matrix[0].size();

        bool zeroInRow0 = false;
        for (int j = 0; j < N; ++j) {
            if (matrix[0][j] == 0) {
                zeroInRow0 = true;
                break;
            }
        }
        bool zeroInColumn0 = false;
        for (int i = 0; i < M; ++i) {
            if (matrix[i][0] == 0) {
                zeroInColumn0 = true;
                break;
            }
        }
        
        for (int i = 1; i < M; ++i) {
            for (int j = 1; j < N; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        // 清零
        for (int i = 1; i < M; ++i) {
            for (int j = 1; j < N; ++j) {
                if (matrix[0][j] == 0 || matrix[i][0] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (zeroInRow0) {
            for (int j = 0; j < N; ++j) {
                matrix[0][j] = 0;
            }
        }
        if (zeroInColumn0) {
            for (int i = 0; i < M; ++i) {
                matrix[i][0] = 0;
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
    
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[0].size(); ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
