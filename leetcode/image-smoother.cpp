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
        const int R = M.size(), C = M[0].size();
        
        vector<vector<int>> ans(R, vector<int>(C, 0));
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                int leftI = max(0, r-1), rightI = min(R-1, r+1);
                int leftJ = max(0, c-1), rightJ = min(C-1, c+1);
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
