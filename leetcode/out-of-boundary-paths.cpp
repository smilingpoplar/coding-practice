//
//  out-of-boundary-paths
//  https://leetcode.com/problems/out-of-boundary-paths/
//
//  Created by smilingpoplar on 17/12/01.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        vector<vector<vector<int>>> memo(N + 1, vector<vector<int>>(m, vector<int>(n, -1)));
        return findPaths(m, n, N, i, j, memo);        
    }
    
    int findPaths(int m, int n, int N, int i, int j, vector<vector<vector<int>>> &memo) {
        if (i < 0 || i >= m || j < 0 || j >= n) return 1;
        if (N == 0) return 0;
        
        if (memo[N][i][j] >= 0) return memo[N][i][j];
        const int MOD = 1000000007;
        int ans = findPaths(m, n, N - 1, i - 1, j, memo);
        ans = (ans + findPaths(m, n, N - 1, i + 1, j, memo)) % MOD;
        ans = (ans + findPaths(m, n, N - 1, i, j - 1, memo)) % MOD;
        ans = (ans + findPaths(m, n, N - 1, i, j + 1, memo)) % MOD;
        memo[N][i][j] = ans;
        return ans;        
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
