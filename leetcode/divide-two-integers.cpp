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
        
        int sign = ((dividend > 0) ^ (divisor > 0)) ? -1 : 1;
        // abs(INT_MIN)溢出成INT_MIN，用"unsigned int"避免int溢出
        unsigned int uDividend = abs(dividend);
        unsigned int uDivisor = abs(divisor);
        
        int result = 0;
        while (uDivisor <= uDividend) {
            unsigned int d = uDivisor;
            int multiple = 1;
            while (d <= (uDividend >> 1)) { // (d<<1)<=uDividend可能溢出
                d <<= 1;
                multiple <<= 1;
            }
            uDividend -= d;
            result += multiple;
        }
        
        return sign * result;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.divide(INT_MAX, 3);
    
    return 0;
}
