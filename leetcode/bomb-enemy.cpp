//
//  bomb-enemy
//  https://leetcode.com/problems/bomb-enemy/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        const int M = grid.size();
        const int N = grid[0].size();
        vector<vector<int>> cnt(M, vector<int>(N, 0));
        int ans = 0;
        
        // 对每行，从左往右扫、从右往左扫
        int count;
        for (int r = 0; r < M; r++) {
            count = 0;
            for (int c = 0; c < N; c++) {
                // 下面的循环体都一样
                if (grid[r][c] == 'W') count = 0;
                else if (grid[r][c] == 'E') count++;
                else cnt[r][c] += count;
            }
            count = 0;
            for (int c = N - 1; c >= 0; c--) {
                if (grid[r][c] == 'W') count = 0;
                else if (grid[r][c] == 'E') count++;
                else cnt[r][c] += count;
            }
        }
        // 对每列，从上往下扫、从下往上扫
        for (int c = 0; c < N; c++) {
            count = 0;
            for (int r = 0; r < M; r++) {
                if (grid[r][c] == 'W') count = 0;
                else if (grid[r][c] == 'E') count++;
                else cnt[r][c] += count;
            }
            count = 0;
            for (int r = M - 1; r >= 0; r--) {
                if (grid[r][c] == 'W') count = 0;
                else if (grid[r][c] == 'E') count++;
                else cnt[r][c] += count;
                ans = max(ans, cnt[r][c]);
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
