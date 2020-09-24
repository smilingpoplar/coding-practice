//
//  transpose-matrix
//  https://leetcode.com/problems/transpose-matrix/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        if (A.empty()) return {};
        const int R = A.size(), C = A[0].size();
        vector<vector<int>> B(C, vector<int>(R));
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                B[c][r] = A[r][c];
            }
        }
        return B;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
