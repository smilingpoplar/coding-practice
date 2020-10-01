//
//  stone-game-iii
//  https://leetcode.com/problems/stone-game-iii/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    string stoneGameIII(vector<int>& stones) {
        // 题目：只能从数组头取，取1、2、3堆
        // 设dp[i]表示stones[i..]、现在Alice取、最大得分
        // Alice得分为正，Bob得分为负
        // dp[i]=max{ sum[i..i+k] - dp[i+k+1] }, k=0,1,2
        const int N = stones.size();
        vector<int> dp(N + 1, 0); // i==N
        for (int i = N - 1; i >= 0; i--) {
            dp[i] = INT_MIN;
            for (int k = 0, sum = 0; k <= 2 && i + k < N; k++) {
                sum += stones[i + k];
                dp[i] = max(dp[i], sum - dp[i + k + 1]);
            }
        }
        if (dp[0] > 0) return "Alice";
        if (dp[0] < 0) return "Bob";
        return "Tie";
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
