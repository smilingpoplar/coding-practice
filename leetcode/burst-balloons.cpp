//
//  burst-balloons
//  https://leetcode.com/problems/burst-balloons/
//
//  Created by smilingpoplar on 17/12/01.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        // nums前后添加1扩展成a
        const int N = (int)nums.size() + 2;
        vector<int> a(N);
        a[0] = a[N-1] = 1;
        for (int i = 1; i < N - 1; i++) {
            a[i] = nums[i - 1];
        }

        // 设dp[i][j]表示a[i..j]戳气球的最大得分，原问题dp[1][N-2]
        // 考虑最后一戳i<=k<=j，得分a[i-1]*a[k]*a[j+1]，还把数组分成两段dp[i][k-1]和dp[k+1][j]
        vector<vector<int>> dp(N, vector<int>(N, 0));
        for (int i = N - 2; i >= 1; i--) {
            for (int j = i; j <= N - 2; j++) {
                for (int k = i; k <= j; k++) {
                    dp[i][j] = max(dp[i][j], a[i-1] * a[k] * a[j+1] + dp[i][k-1] + dp[k+1][j]);
                }
            }
        }
        return dp[1][N-2];
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
