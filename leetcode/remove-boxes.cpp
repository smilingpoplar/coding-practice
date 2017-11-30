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
        vector<vector<vector<int>>> dp(N, vector<vector<int>>(N, vector<int>(N, 0)));
        // 初始化len==1的情况
        for (int i = 0; i < N; i++) {
            for (int k = 0; k <= i; k++) {
                dp[i][i][k] = (k + 1) * (k + 1);
            }
        }
        for (int len = 2; len <= N; len++) {
            for (int i = 0; i <= N - len; i++) {
                int j = i + len - 1;
                for (int k = 0; k <= i; k++) { // 前面有k个与boxes[i]同色
                    dp[i][j][k] = (k + 1) * (k + 1) + dp[i + 1][j][0]; // 现在拿boxes[i]
                    for (int m = i + 1; m < N; m++) {
                        if (boxes[m] == boxes[i]) { // 以后和后面同色的boxes[m]一起拿
                            dp[i][j][k] = max(dp[i][j][k], dp[i + 1][m - 1][0] + dp[m][j][k + 1]);
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
