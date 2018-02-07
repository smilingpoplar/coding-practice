//
//  integer-break
//  https://leetcode.com/problems/integer-break/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        // 从v[1..n-1]这n-1个数中取数字，完全背包问题
        // 设dp[i][j]表示v[1..i]中取数字、剩余和为j时的最大积
        // dp[i][j] = max( dp[i-1][j], i * dp[i][j-i] )
        // 完全背包的一维数组写法
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i < n; i++) {
            for (int j = i; j <= n; j++) { // 正序遍历
                dp[j] = max(dp[j], i * dp[j - i]);
            }
        }
        return dp[n];
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
