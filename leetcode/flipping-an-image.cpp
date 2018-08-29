//
//  flipping-an-image
//  https://leetcode.com/problems/flipping-an-image/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        const int R = A.size(), C = A[0].size();
        vector<vector<int>> B(R, vector<int>(C));
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                B[r][C-1-c] = !A[r][c];
            }
        }
        return B;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
