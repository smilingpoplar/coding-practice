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
    // 求得分在[K,N]间的概率
    double new21Game(int N, int K, int W) {
        if (K == 0 || K + W - 1 <= N) return 1;
        // 设dp[i]表示得分i的概率，dp[i]= sum(dp[i-W..i-1])/W；
        // 可是dp[K..i-1]已是终止态，不能再从它们跳到dp[i]；
        // 所以 dp[i] = sum(dp[i-W .. min(K-1,i-1)]) / W
        // 初始dp[0]=1
        vector<double> dp(N + 1, 0);
        dp[0] = 1;
        double sum = dp[0], ans = 0;
        for (int i = 1; i <= N; i++) {
            dp[i] = sum / W;
            if (i < K) sum += dp[i]; // min(K-1,i-1)=i-1
            else ans += dp[i]; // i>=K，恰好放else语句
            if (i >= W) sum -= dp[i-W];
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
