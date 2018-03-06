//
//  cherry-pickup
//  https://leetcode.com/problems/cherry-pickup/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        // (0,0)=>(N-1,N-1)的两条路径同时走k步，分别走到(r1,k-r1)、(r2,k-r2)，
        // 设dp[k][r1][r2]表示从(0,0)走到(r1,k-r1)、(r2,k-r2)可摘草莓的最大数。
        // dp[k][r1][r2] = grid[r1][k-r1] + grid[r2][k-r2]
        //      + max{ dp[k-1][r1][r2], dp[k-1][r1][r2-1], dp[k-1][r1-1][r2], dp[k-1][r1-1][r2-1] }
        // max{...}里面表示两条路径同时走一步的四种情况：c1、c2走一步，c1、r2走一步、r1、c2走一步、r1、r2走一步
        // 0<=k<=2*(N-1)；0<=r1<=N-1、0<=k-r1<=N-1；r2取值范围类似r1
        // dp[k][][]只依赖于dp[k-1][][]，降维
        const int N = grid.size();
        vector<vector<int>> dp(N, vector<int>(N, -1));
        dp[0][0] = grid[0][0];
        for (int k = 1; k <= 2*(N-1); k++) {
            vector<vector<int>> next(N, vector<int>(N, -1));
            for (int r1 = 0; r1 < N; r1++) {
                for (int r2 = 0; r2 < N; r2++) {
                    int c1 = k - r1, c2 = k - r2;
                    if (c1 < 0 || c1 >= N || c2 < 0 || c2 >= N || grid[r1][c1] < 0 || grid[r2][c2] < 0) continue;
                    int theMax = dp[r1][r2];
                    if (r2 > 0) theMax = max(theMax, dp[r1][r2-1]);
                    if (r1 > 0) theMax = max(theMax, dp[r1-1][r2]);
                    if (r1 > 0 && r2 > 0) theMax = max(theMax, dp[r1-1][r2-1]);
                    if (theMax < 0) continue; // 不通
                    // 防止重复统计同一格
                    next[r1][r2] = grid[r1][c1] + theMax;
                    if (r1 != r2) next[r1][r2] += grid[r2][c2];
                }
            }
            swap(next, dp);
        }
        return max(0, dp[N-1][N-1]);
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
