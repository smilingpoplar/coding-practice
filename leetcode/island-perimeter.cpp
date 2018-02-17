//
//  island-perimeter
//  https://leetcode.com/problems/island-perimeter/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        // 周长 = 4*块的个数 - 2*内边的个数
        // 每块只要看和右块、和下块有没重叠
        if (grid.empty()) return 0;
        const int M = grid.size();
        const int N = grid[0].size();
        int count = 0, internal = 0;
        for (int r = 0; r < M; r++) {
            for (int c = 0; c < N; c++) {
                if (grid[r][c] == 1) {
                    count++;
                    if (r < M - 1 && grid[r+1][c] == 1) internal++;
                    if (c < N - 1 && grid[r][c+1] == 1) internal++;
                }
            }
        }
        return 4 * count - 2 * internal;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
