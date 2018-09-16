//
//  race-car
//  https://leetcode.com/problems/race-car/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int racecar(int target) {
        vector<int> dp(target + 1, 0);
        for (int t = 1; t <= target; t++) {
            // 走n步A前进 2^0+2^1+...+2^(n-1) = 2^n-1
            // 首先尽量接近t：2^n-1 <= t < 2^(n+1)-1
            // 1. 走n步A快达或到达t时停下
            // 2. 走n+1步A超过t时停下
            int n = log2(t + 1);
            int near = dist(n);
            if (near == t) {
                dp[t] = n;
                continue;
            }
            // 情况1可回退m步A（0<=m<n），再掉头前进；情况2，掉头前进
            int ans = INT_MAX;
            for (int m = 0; m < n; m++) {
                ans = min(ans, n + 1 + m + 1 + dp[t - (near - dist(m))]);
            }
            ans = min(ans, n + 1 + 1 + dp[dist(n + 1) - t]); 
            dp[t] = ans;
        }        
        return dp[target];
    }
    
    int dist(int steps) {
        return (1 << steps) - 1;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
