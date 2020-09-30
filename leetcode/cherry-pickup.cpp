//
//  cherry-pickup
//  https://leetcode.com/problems/cherry-pickup/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        // (0,0)=>(N-1,N-1)的两条路径同时走k步，满足条件：k==r1+c1==r2+c2
        // 设dp[k][r1][r2]表示从(0,0)走到(r1,c1)、(r2,c2)可摘草莓的最大数。
        // 两条路径同时走一步有四种情况：c1、c2走一步，c1、r2走一步、r1、c2走一步、r1、r2走一步
        // dp[k][r1][r2] = grid[r1][c1] + grid[r2][c2] /*r1==r2时不重复统计这项*/
        //      + max{ dp[k-1][r1][r2], dp[k-1][r1][r2-1], dp[k-1][r1-1][r2], dp[k-1][r1-1][r2-1] }
        // 0<=k<=2*(N-1)；0<=r1<=N-1、0<=c1<=N-1；r2取值范围类似r1
        const int N = grid.size();
        vector<vector<vector<int>>> memo(2 * (N - 1) + 1, vector<vector<int>>(N, vector<int>(N, INT_MIN)));
        int ans = dfs(2 * (N - 1), N - 1, N - 1, grid, memo);
        return ans == -1 ? 0 : ans;
    }

    int dfs(int k, int r1, int r2, vector<vector<int>>& grid,
            vector<vector<vector<int>>>& memo) {
        if (k == 0 && r1 == 0 && r2 == 0) return grid[0][0];
        int c1 = k - r1, c2 = k - r2;
        if (r1 < 0 || c1 < 0 || r2 < 0 || c2 < 0 
            || grid[r1][c1] < 0 || grid[r2][c2] < 0) return -1;
        if (memo[k][r1][r2] != INT_MIN) return memo[k][r1][r2];

        int ans = -1;
        ans = max(ans, dfs(k - 1, r1, r2, grid, memo));
        ans = max(ans, dfs(k - 1, r1, r2 - 1, grid, memo));
        ans = max(ans, dfs(k - 1, r1 - 1, r2, grid, memo));
        ans = max(ans, dfs(k - 1, r1 - 1, r2 - 1, grid, memo));
        if (ans >= 0) {
            ans += r1 == r2 ? grid[r1][c1] : grid[r1][c1] + grid[r2][c2];
        }   
        return memo[k][r1][r2] = ans;
    }
};

/*
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        // (0,0)=>(N-1,N-1)的两条路径同时走k步，满足条件：k==r1+c1==r2+c2
        // 设dp[k][r1][r2]表示从(0,0)走到(r1,c1)、(r2,c2)可摘草莓的最大数。
        // 两条路径同时走一步有四种情况：c1、c2走一步，c1、r2走一步、r1、c2走一步、r1、r2走一步
        // dp[k][r1][r2] = grid[r1][c1] + grid[r2][c2] // r1==r2时不重复统计这项
        //      + max{ dp[k-1][r1][r2], dp[k-1][r1][r2-1], dp[k-1][r1-1][r2], dp[k-1][r1-1][r2-1] }
        // 0<=k<=2*(N-1)；0<=r1<=N-1、0<=c1<=N-1；r2取值范围类似r1
        // 递推式在k这维只依赖k-1项，省掉k这维，k仍从左往右遍历
        const int N = grid.size();
        vector<vector<int>> dp(N, vector<int>(N, -1));
        dp[0][0] = grid[0][0]; // 已知grid[0][0]!=-1
        
        for (int k = 1; k <= 2*(N-1); k++) {
            vector<vector<int>> ndp(N, vector<int>(N, -1)); // 用-1表示路不通
            for (int r1 = 0; r1 < N; r1++) {
                for (int r2 = 0; r2 < N; r2++) {
                    int c1 = k - r1, c2 = k - r2;
                    if (c1 < 0 || c1 >= N || c2 < 0 || c2 >= N 
                        || grid[r1][c1] < 0 || grid[r2][c2] < 0) continue;
                    
                    int theMax = dp[r1][r2];
                    if (r2 > 0) theMax = max(theMax, dp[r1][r2-1]);
                    if (r1 > 0) theMax = max(theMax, dp[r1-1][r2]);
                    if (r1 > 0 && r2 > 0) theMax = max(theMax, dp[r1-1][r2-1]);
                    if (theMax < 0) continue; // 路不通

                    int pick = r1 == r2 ? grid[r1][c1] : grid[r1][c1] + grid[r2][c2];
                    ndp[r1][r2] = theMax + pick;
                }
            }
            swap(dp, ndp);
        }
        return max(0, dp[N-1][N-1]);
    }
};
*/

int main(int argc, const char * argv[]) {
    return 0;
}
