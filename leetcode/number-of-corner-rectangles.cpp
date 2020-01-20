//
//  number-of-corner-rectangles
//  https://leetcode.com/problems/number-of-corner-rectangles/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        const int R = grid.size(), C = grid[0].size();
        int ans = 0;
        // 遍历两个行
        for (int r1 = 0; r1 < R; r1++) {
            for (int r2 = r1 + 1; r2 < R; r2++) {
                int cnt = 0; // “某列两端同为1”的列数
                for (int c = 0; c < C; c++) {
                    if (grid[r1][c] && grid[r2][c]) cnt++;
                }
                ans += cnt * (cnt - 1) / 2;
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
