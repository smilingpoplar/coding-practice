//
//  image-smoother
//  https://leetcode.com/problems/image-smoother/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        const int nRows = M.size();
        const int nCols = M[0].size();
        
        vector<vector<int>> ans(nRows, vector<int>(nCols, 0));
        for (int r = 0; r < nRows; r++) {
            for (int c = 0; c < nCols; c++) {
                int leftI = max(0, r-1), rightI = min(nRows-1, r+1);
                int leftJ = max(0, c-1), rightJ = min(nCols-1, c+1);
                int count = 0;
                for (int i = leftI; i <= rightI; i++) {
                    for (int j = leftJ; j <= rightJ; j++) {
                        ans[r][c] += M[i][j];
                        count++;
                    }
                }
                ans[r][c] /= count;
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
