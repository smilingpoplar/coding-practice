//
//  surface-area-of-3d-shapes
//  https://leetcode.com/problems/surface-area-of-3d-shapes/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        // 每根柱子贡献面积4*v+2，还要减去两两间的重合面积min(v1,v2)*2
        const int N = grid.size();
        int ans = 0;
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                if (grid[r][c] > 0) ans += 4 * grid[r][c] + 2;
                if (r > 0) ans -= min(grid[r][c], grid[r-1][c]) * 2;
                if (c > 0) ans -= min(grid[r][c], grid[r][c-1]) * 2;
            }
        }
        return ans;        
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
