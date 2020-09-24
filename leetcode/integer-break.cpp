//
//  integer-break
//  https://leetcode.com/problems/integer-break/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        // 若可以分割成浮点数，n = x*(n/x)，prod = x^(n/x)
        // 要最大化prod，将其导数取零，得x=自然对数e=2.71828，
        // 所以尽量分割成更接近e的3、不行再取2
        // 3*(n-3) >= 2*(n-2) > n => n>4，所以n>4时一定取3
        // n<=4时特殊处理（已知n>=2）
        if (n == 2) return 1;
        if (n == 3) return 2;
        
        int prod = 1;
        while (n > 4) {
            prod *= 3;
            n -= 3;
        }
        prod *= n;
        return prod;
    }
};

/*
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
*/

int main(int argc, const char * argv[]) {    
    return 0;
}
