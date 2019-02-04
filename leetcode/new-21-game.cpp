//
//  new-21-game
//  https://leetcode.com/problems/new-21-game/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // <K时不断得[1..W]分，求最后得分在[K..N]间的概率
    double new21Game(int N, int K, int W) {
        if (K == 0 || K - 1 + W <= N) return 1;
        // 设dp[i]表示得分为i的概率，dp[i]= sum(dp[i-W..i-1])/W；
        // 但dp[K..i-1]已是终止态，不能再从它们跳到dp[i]，
        // 所以 dp[i] = sum(dp[i-W .. min(K-1,i-1)]) / W
        // 初始dp[0]=1
        // 
        // 记范围和sum(dp[i-W .. min(K-1,i-1)]) = wSum
        // i增大时，维护滑动窗口wSum，扩展右边收缩左边
        vector<double> dp(N + 1, 0);
        dp[0] = 1;
        double wSum = dp[0], ans = 0;
        for (int i = 1; i <= N; i++) {
            dp[i] = wSum / W;
            // 维护wSum
            if (i < K) wSum += dp[i]; // min(K-1,i-1)=i-1，扩展窗口右边
            else ans += dp[i]; // i>=K，不用扩展窗口右边；统计[K..N]间的概率
            if (i >= W) wSum -= dp[i-W];
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
