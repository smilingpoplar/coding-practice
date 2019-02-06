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
        // 走n步A前进 dist(n) = 2^0+2^1+...+2^(n-1) = 2^n-1
        // 设dp[i]表示从位置0到位置i需要的最少指令数，
        // 为走到位置i，先尽量接近i：dist(n) <= i < dist(n+1)
        // 1. 走n步A，到达或快达i；若快达i，可回退m步A（0<=m<n），再掉头前进，
        //    需要 n + 1（掉头）+ m（回退m步）+ 1（掉头）步
        // 2. 走n+1步A，超过i，可掉头前进，
        //    需要 n + 1 + 1（掉头）步
        vector<int> dp(target + 1, 0);
        for (int i = 1; i <= target; i++) {
            int n = log2(i + 1), dn = dist(n);
            if (dn == i) { // 到达i
                dp[i] = n;
                continue;
            }

            int ans = INT_MAX;
            // 快达i
            for (int m = 0; m < n; m++) {
                ans = min(ans, n + 1 + m + 1 + dp[i - dn + dist(m)]);
            }
            // 超过i
            ans = min(ans, n + 1 + 1 + dp[dist(n + 1) - i]); 
            dp[i] = ans;
        }        
        return dp[target];
    }
    
    int dist(int n) {
        return (1 << n) - 1;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
