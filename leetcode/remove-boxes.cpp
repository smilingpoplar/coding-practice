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
        // 设dp[i][j][k]表示boxes[i..j]且前面有k个与boxes[i]同色且待拿的盒子时的最大得分
        // 考虑现在拿boxes[i]还是留着以后和后面同色的一起拿
        vector<vector<vector<int>>> dp(N, vector<vector<int>>(N, vector<int>(N, 0)));
        // i == j
        for (int i = 0; i < N; i++) {
            for (int k = 0; k <= i; k++) {
                dp[i][i][k] = (k + 1) * (k + 1);
            }
        }
        // i < j
        for (int i = N - 2; i >= 0; i--) {
            for (int j = i + 1; j < N; j++) {
                for (int k = 0; k <= i; k++) { // 前面有k个与boxes[i]同色
                    dp[i][j][k] = (k + 1) * (k + 1) + dp[i + 1][j][0]; // 现在拿boxes[i]
                    for (int m = i + 1; m <= j; m++) {
                        if (boxes[m] == boxes[i]) { // 以后和后面同色的boxes[m]一起拿
                            dp[i][j][k] = max(dp[i][j][k], dp[m][j][k + 1] + dp[i + 1][m - 1][0]);
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
