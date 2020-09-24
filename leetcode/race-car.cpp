//
//  race-car
//  https://leetcode.com/problems/race-car/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int racecar(int target) {
        // 走n步A前进 dist(n) = 2^0+2^1+...+2^(n-1) = 2^n-1
        // 设dp[i]表示前进i距离需要的最少指令数，
        // 为走到位置i，先尽量接近i：dist(n) <= i < dist(n+1)
        // 1) 走n步A，到达或快达i。若是快达i，可回退m步A（0<=m<n），再掉头前进，
        //    需要 n + 1（掉头）+ m（回退m步）+ 1（掉头）步 + dp[剩余距离]
        // 2) 走n+1步A，超过i，可掉头前进，
        //    需要 n + 1 + 1（掉头）步 + dp[超出距离]
        vector<int> dp(target + 1, 0);
        for (int i = 1; i <= target; i++) {
            int n = log2(i + 1); // dist(n)=2^n-1 <= i
            if (dist(n) == i) { // 到达i
                dp[i] = n;
                continue;
            }

            int ans = INT_MAX;
            // 快达i
            for (int m = 0; m < n; m++) {
                ans = min(ans, n + 1 + m + 1 + dp[i - dist(n) + dist(m)]);
            }
            // 超过i
            ans = min(ans, n + 1 + 1 + dp[dist(n+1) - i]); 
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
