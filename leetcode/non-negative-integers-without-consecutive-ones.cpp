//
//  non-negative-integers-without-consecutive-ones
//  https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/
//
//  Created by smilingpoplar on 17/12/02.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int findIntegers(int num) {
        // 设f[i]表示i位二进制中无连续1s的数的有多少个，根据最高位是0还是1
        // f[i] = f[i-1]/*最高位0*/ + f[i-2]/*最高位1*/，初始f[1]=2、f[2]=3，推得f[0]=1
        const int bitLen = sizeof(num) * 8;
        vector<int> f(bitLen);
        f[0] = 1, f[1] = 2;
        for (int i = 2; i < bitLen; i++) {
            f[i] = f[i-1] + f[i-2];
        }
        
        int count = 0;
        // 该循环统计<n的所求数有多少个
        for (int i = bitLen - 1; i >= 0; i--) {
            if (num & (1 << i)) { // 第i位为1
                count += f[i]; // 把第i位固定为0，后面[0..i-1]的i位数贡献f[i]
                if (num & (1 << (i+1))) return count; // 若遇到连续1s提前结束统计
            }
        }
        return count + 1; // 1是算上n本身        
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
