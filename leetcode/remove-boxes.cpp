//
//  remove-boxes
//  https://leetcode.com/problems/remove-boxes/
//
//  Created by smilingpoplar on 17/11/30.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        const int N = boxes.size();
        // 设dp[i][j][k]表示boxes[i..j]、前面有连续k个未拿盒子和boxes[i]同色时的最大得分
        // 0<=i<=j<N，0<=k<=i
        // 分情况：现在拿boxes[i]、还是将来遇到同色时再考虑
        // 现在拿，dp[i][j][k] = (k + 1) * (k + 1) + dp[i+1][j][0];
        // 将来遇到同色时再考虑，dp[i][j][k] = dp[i+1][m-1][0] + dp[m][j][k+1];
        // i从右往左遍历，j从左往右遍历
        vector<vector<vector<int>>> dp(N, vector<vector<int>>(N, vector<int>(N, 0)));
        // i == j
        for (int i = 0; i < N; i++) {
            for (int k = 0; k <= i; k++) {
                dp[i][i][k] = (k + 1) * (k + 1); // 现在拿boxes[i]
            }
        }
        // i < j
        for (int i = N - 2; i >= 0; i--) {
            for (int j = i + 1; j < N; j++) {
                for (int k = 0; k <= i; k++) { // 前面有连续k个未拿盒子与boxes[i]同色
                    dp[i][j][k] = (k + 1) * (k + 1) + dp[i+1][j][0]; // 现在拿boxes[i]
                    for (int m = i + 1; m <= j; m++) {
                        if (boxes[m] == boxes[i]) { // 将来遇到同色的boxes[m]时再考虑
                            dp[i][j][k] = max(dp[i][j][k], dp[i+1][m-1][0] + dp[m][j][k+1]);
                        }
                    }
                }
            }
        }
        return dp[0][N-1][0];
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
