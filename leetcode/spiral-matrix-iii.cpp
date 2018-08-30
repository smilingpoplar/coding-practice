//
//  spiral-matrix-iii
//  https://leetcode.com/problems/spiral-matrix-iii/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        // 往右下左上方向不断走1,1,2,2,3,3,4,4,5,5,...步
        // 从索引n生成1,1,2,2,3,3,4,4,5,5,...的通式是 n/2+1
        vector<vector<int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        vector<vector<int>> ans;
        ans.push_back({r0, c0});
        
        int r = r0, c = c0;
        for (int n = 0; ans.size() < R * C; n++) {
            auto &dir = dirs[n%4]; // 方向
            for (int k = 0; k < n / 2 + 1; k++) { // 走n/2+1步
                r += dir[0], c += dir[1];
                if (0 <= r && r < R && 0 <= c && c < C) ans.push_back({r, c});
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
