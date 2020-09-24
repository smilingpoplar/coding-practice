//
//  count-numbers-with-unique-digits
//  https://leetcode.com/problems/count-numbers-with-unique-digits/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        // dp[0]  1
        // dp[1]  dp[0]+9
        // dp[2]  dp[1]+9*9
        // dp[3]  dp[2]+9*9*8
        // ...
        // dp[k]  dp[k-1]+9*9*8*7*6*5*4*3*2*1*0，k为11
        if (n == 0) return 1;
        int prod = 9, ans = 10; // 对应dp[1]行
        for (int i = 2; i <= min(n, 10); i++) {
            prod *= 11 - i;
            ans += prod;
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {   
    return 0;
}
