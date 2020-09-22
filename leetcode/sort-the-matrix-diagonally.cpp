//
//  sort-the-matrix-diagonally
//  https://leetcode.com/problems/sort-the-matrix-diagonally/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        const int R = mat.size(), C = mat[0].size();
        // 每条主对角线上r-c值相同，当作桶下标，桶用最小堆
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> diags;
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                diags[r-c].push(mat[r][c]);
            }
        }
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                mat[r][c] = diags[r-c].top();
                diags[r-c].pop();
            }
        }
        return mat;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
