//
//  perfect-squares
//  https://leetcode.com/problems/perfect-squares/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        // 设dp[i]表示和值为i的完全平方数最少个数
        // dp[i] = min( dp[i-j*j]+1 /*分离出数j*/)，1<=j*j<=i
        // 初始dp[0]=0
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j * j <= i; j++) {
                dp[i] = min(dp[i], dp[i - j*j] + 1);
            }
        }
        return dp[n];
    }    
};

int main(int argc, const char * argv[]) {    
    return 0;
}
