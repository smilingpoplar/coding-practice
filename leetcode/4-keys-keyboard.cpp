//
//  4-keys-keyboard
//  https://leetcode.com/problems/4-keys-keyboard/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxA(int N) {
        // dp[i]表示按i次键盘时A的最大个数，
        // 一种是按1次A，dp[i]=dp[i-1]+1
        // 一种是按3<=k<=i次，ctrlA+ctrlC+(k-2)ctrlV，dp[i]=max{dp[i-k]*(k-1)}
        vector<int> dp(N + 1, 0);
        for (int i = 1; i <= N; i++) {
            dp[i] = dp[i-1] + 1;
            for (int k = 3; k <= i; k++) {
                dp[i] = max(dp[i], dp[i-k] * (k-1));
            }
        }
        return dp[N];
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
