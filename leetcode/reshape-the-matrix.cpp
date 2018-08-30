//
//  reshape-the-matrix
//  https://leetcode.com/problems/reshape-the-matrix/
//
//  Created by smilingpoplar on 17/12/01.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if (nums.empty()) return nums;
        const int M = nums.size(), N = nums[0].size();
        if (M * N != r * c) return nums;
        
        vector<vector<int>> matrix(r, vector<int>(c));
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                int idx = i * N + j;
                matrix[idx / c][idx % c] = nums[i][j];
            }
        }
        return matrix;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
