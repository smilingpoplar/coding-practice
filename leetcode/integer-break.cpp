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
        // 从[1..n-1]中取数，完全背包问题
        // n是背包容量，取的数i是物品体积，数i也是物品价值
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i < n; i++) {
            for (int v = i; v <= n; v++) { // 正序遍历各个容量
                dp[v] = max(dp[v], i * dp[v - i]);
            }
        }
        return dp[n];
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
