//
//  new-21-game
//  https://leetcode.com/problems/new-21-game/
//
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
        // 设dp[i]表示得分为i的概率，Wsum表示前W个dp[]的和sum{dp[i-W..i-1]}，则dp[i]=Wsum/W
        // 由于得分>=K就不再得分，Wsum不能包含dp[K..i-1]，Wsum=sum{dp[i-W..min(K-1,i-1)]}
        // 维护长<=W的窗口，随着i增大更新Wsum
        vector<double> dp(N + 1, 0);
        dp[0] = 1;
        double Wsum = dp[0], ans = 0;
        for (int i = 1; i <= N; i++) {
            dp[i] = Wsum / W;
            // 更新Wsum
            if (i < K) Wsum += dp[i]; // min(K-1,i-1)=i-1，扩展窗口右边界
            else ans += dp[i]; // min(K-1,i-1)=i-1，不用扩展窗口右边界；i>=K，正好可以统计[K..N]间的概率
            if (i-W >= 0) Wsum -= dp[i-W]; // 收缩窗口左边界
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
