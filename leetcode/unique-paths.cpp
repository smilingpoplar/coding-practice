//
//  unique-paths
//  https://leetcode.com/problems/unique-paths/
//
//  Created by smilingpoplar on 15/5/24.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        // 设f(i,j)表示从[0,0]到[m-1,n-1]的路径数，0<=i<=m-1，0<=j<=n-1，
        // 可以往右往下走，f(i,j) = f(i-1,j) + f(i,j-1)
        vector<vector<int>> f(m, vector<int>(n, 0));
        for (int i = 0; i <= m - 1; i++) f[i][0] = 1;
        for (int j = 0; j <= n - 1; j++) f[0][j] = 1;
        for (int i = 1; i <= m - 1; i++) {
            for (int j = 1; j <= n - 1; j++) {
                f[i][j] = f[i - 1][j] + f[i][j - 1];
            }
        }
        return f[m - 1][n - 1];
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.uniquePaths(3, 7);
    
    return 0;
}
