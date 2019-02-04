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
        // 最后戳破的气球k将区间[0..n-1]分成两区间[0..k-1]、[k+1..n-1]，两区间的得分互不影响，这就是子问题。
        // 对任意区间nums[i..j]考虑其最后一戳k，设dp[i][j]表示a[i..j]戳气球的最大得分，
        // dp[i][j] = nums[i-1]*nums[k]*nums[j+1]（戳破气球k得分）+ dp[i][k-1] + dp[k+1][j]，i<=k<=j
        // i维上i依赖于k+1(>i)，i逆序遍历；j维上j依赖于k-1(<j)，j正序遍历


        // 先把nums前后添加1扩展成a，设N是扩展后的长度，则1<=i<=j<=N-2，所求dp[1][N-2]    
        const int N = (int)nums.size() + 2;
        vector<int> a(N);
        a[0] = a[N-1] = 1;
        for (int i = 1; i < N - 1; i++) {
            a[i] = nums[i-1];
        }

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
