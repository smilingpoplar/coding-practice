//
//  transpose-matrix
//  https://leetcode.com/problems/transpose-matrix/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        if (A.empty()) return {};
        const int M = A.size(), N = A[0].size();
        vector<vector<int>> B(N, vector<int>(M));
        for (int r = 0; r < M; r++) {
            for (int c = 0; c < N; c++) {
                B[c][r] = A[r][c];
            }
        }
        return B;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
