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
        // 设f(i-1,j-1)表示ixj网格的路径数，1<=i<=m，1<=j<=n，
        // 可以往右往下走，f(i-1,j-1) = f(i-2,j-1) + f(i-1,j-2)
        vector<vector<int>> f(m, vector<int>(n, 0));
        for (int i = 1; i <= m; ++i) f[i - 1][0] = 1;
        for (int j = 1; j <=n; ++j) f[0][j - 1] = 1;
        for (int i = 2; i <= m; ++i) {
            for (int j = 2; j <=n; ++j) {
                f[i - 1][j - 1] = f[i - 2][j - 1] + f[i - 1][j - 2];
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
