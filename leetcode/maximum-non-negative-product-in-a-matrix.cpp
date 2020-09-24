//
//  maximum-non-negative-product-in-a-matrix
//  https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        // 设mx[r][c]表示从(0,0)往右往下到(r,c)的最大乘积
        //  mn[r][c]                          最小乘积
        // mn[r][c], mx[r][c] =  
        //     minmax(grid[r][c] * min(mn[r-1][c], mn[r][c-1]), 
        //            grid[r][c] * max(mx[r-1][c], mx[r][c-1]))
        const int MOD = 1e9 + 7;
        const int R = grid.size(), C = grid[0].size();
        vector<vector<long>> mx(R, vector<long>(C)), 
                             mn(R, vector<long>(C));
        // 初始化
        mn[0][0] = mx[0][0] = grid[0][0];
        for (int c = 1; c < C; c++) {
            mn[0][c] = mx[0][c] = (grid[0][c] * mn[0][c-1]);
        }
        for (int r = 1; r < R; r++) {
            mn[r][0] = mx[r][0] = (grid[r][0] * mn[r-1][0]);
        }
        for (int r = 1; r < R; r++) {
            for (int c = 1; c < C; c++) {
                long a = (grid[r][c] * min(mn[r-1][c], mn[r][c-1]));
                long b = (grid[r][c] * max(mx[r-1][c], mx[r][c-1]));
                mn[r][c] = min(a, b);
                mx[r][c] = max(a, b);
            }
        }
        // pitfalls: 只对ans取模，在上面过程中取模会出错
        int ans = mx[R-1][C-1] % MOD;
        return ans < 0 ? -1 : ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
