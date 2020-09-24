//
//  min-cost-climbing-stairs
//  https://leetcode.com/problems/min-cost-climbing-stairs/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // 设dp[i]表示从i-th开始爬起的最小代价
        // dp[i]=cost[i]+min(dp[i+1], dp[i+2])
        // 初始dp[N]=0, dp[N+1]=0
        const int N = cost.size();
        int dp1 = 0, dp2 = 0;
        for (int i = N -1; i >= 0; i--) {
            int dp = cost[i] + min(dp1, dp2);
            dp2 = dp1;
            dp1 = dp;
        }
        return min(dp1, dp2);
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
