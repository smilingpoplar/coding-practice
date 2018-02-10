//
//  nth-digit
//  https://leetcode.com/problems/nth-digit/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        // [1..9]：1*9，[10..99]：2*90，[100..999]：3*900... k*9*base
        int k = 1;
        long base = 1;
        while (k * 9 * base < n) {
            n -= k * 9 * base;
            k++;
            base *= 10;
        }
        n--; // n变成0-based索引
        long num = base + n / k; // k个数字的数中第n/k个数
        int idx = k - 1 - n % k; // num中自右向左第idx位数字
        for (int i = 0; i < idx; i++) 
            num /= 10;
        num %= 10;
        return num;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
