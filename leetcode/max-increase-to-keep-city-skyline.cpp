//
//  max-increase-to-keep-city-skyline
//  https://leetcode.com/problems/max-increase-to-keep-city-skyline/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        // 横看skyline是各行最大值rowMax[]，竖看skyline是各列最大值colMax[]
        // 新的高度gridNew[r][c] = min(rowMax[r], colMax[c])
        const int R = grid.size();
        const int C = grid[0].size();
        vector<int> rowMax(R, 0);
        vector<int> colMax(C, 0);
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                rowMax[r] = max(rowMax[r], grid[r][c]);
                colMax[c] = max(colMax[c], grid[r][c]);
            }
        }
        
        int ans = 0;
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                ans += min(rowMax[r], colMax[c]) - grid[r][c];
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
