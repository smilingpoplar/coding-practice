//
//  unique-paths
//  https://leetcode.com/problems/unique-paths/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        // 设dp[i][j]表示从[0,0]到[i,j]的路径数，0<=i<m，0<=j<n，
        // 可以往右往下走，dp[i][j] = dp[i-1][j] + dp[i][j-1]
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
            dp[i][0] = 1;
        for (int j = 0; j < n; j++)
            dp[0][j] = 1;

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.uniquePaths(3, 7);
    
    return 0;
}
