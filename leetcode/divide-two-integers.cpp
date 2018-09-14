//
//  divide-two-integers
//  https://leetcode.com/problems/divide-two-integers/
//
//  Created by smilingpoplar on 15/6/24.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0) return INT_MAX;
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        
        int sign = (dividend ^ divisor) >= 0 ? 1 : -1;
        // abs(INT_MIN)溢出成INT_MIN，用labs()避免溢出
        long dvd = labs(dividend), dvs = labs(divisor);
        
        int ans = 0;
        while (dvs <= dvd) {
            long tmp = dvs, mult = 1;
            // 看dvs能翻几倍
            while ((tmp << 1) <= dvd) {
                tmp <<= 1;
                mult <<= 1;
            }
            dvd -= tmp;
            ans += mult;
        }
        return sign * ans;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.divide(INT_MAX, 3);
    
    return 0;
}
