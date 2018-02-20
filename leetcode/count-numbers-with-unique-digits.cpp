//
//  count-numbers-with-unique-digits
//  https://leetcode.com/problems/count-numbers-with-unique-digits/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        // dp[0]  1
        // dp[1]  9+dp[0]
        // dp[2]  9*9+dp[1]
        // dp[3]  9*9*8+dp[2]
        // ...
        // dp[k]  9*9*8*7*6*5*4*3*2*1*0+dp[k-1]，k为11
        if (n == 0) return 1;
        int prev = 1;
        int prod = 9;
        for (int i = 2; i <= min(n, 10); i++) {
            prev += prod;
            prod *= (11 - i);
        }
        return prod + prev;
    }
};

int main(int argc, const char * argv[]) {   
    return 0;
}