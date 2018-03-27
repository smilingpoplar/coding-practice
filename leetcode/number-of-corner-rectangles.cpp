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
        const int M = grid.size();
        const int N = grid[0].size();
        int ans = 0;
        // 遍历两个行
        for (int i = 0; i < M; i++) {
            for (int j = i + 1; j < M; j++) {                
                int cnt = 0; // "某列同为1"的个数
                for (int k = 0; k < N; k++) {
                    if (grid[i][k] && grid[j][k]) cnt++;                    
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
