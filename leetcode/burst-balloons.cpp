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
        // nums扩展成a
        const int N = (int)nums.size() + 2;
        vector<int> a(N);
        a[0] = a[N - 1] = 1;
        for (int i = 1; i < N - 1; i++) {
            a[i] = nums[i - 1];
        }

        vector<vector<int>> dp(N, vector<int>(N, 0));
        for (int i = N - 1; i >= 1; i--) { // dp[i,..]依赖于它右边的值，逆序遍历
            for (int j = i; j < N - 1; j++) { // dp[..,j]依赖于它左边的值，正序遍历
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
