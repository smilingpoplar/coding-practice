//
//  minimum-falling-path-sum
//  https://leetcode.com/problems/minimum-falling-path-sum/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        // 设dp[r][c]表示落到A[r][c]时的最小下降路径和
        // dp[r][c] = A[r][c] + min(dp[r-1][c-1], dp[r-1][c], dp[r-1][c+1])
        // 初始 dp[0][c] = A[0][c]
        // 递推式在r维上只依赖r-1项，省掉r维，要用临时变量
        // ndp[c] = A[r][c] + min(dp[c-1], dp[c], dp[c+1])
        if (A.empty()) return 0;
        const int R = A.size(), C = A[0].size();
        vector<int> dp = A[0];
        for (int r = 1; r < R; r++) {
            vector<int> ndp(C);
            for (int c = 0; c < C; c++) {
                int minVal = dp[c];
                if (c - 1 >= 0) minVal = min(minVal, dp[c-1]);
                if (c + 1 < C) minVal = min(minVal, dp[c+1]);
                ndp[c] = A[r][c] + minVal;
            }
            swap(ndp, dp);
        }
        return *min_element(dp.begin(), dp.end());
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
