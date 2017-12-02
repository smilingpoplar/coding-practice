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
        // 设f[i]表示i位二进制中满足没有连续1s数的个数，根据首位是0还是1
        // f[i] = f[i-1]/*首位0*/ + f[i-2]/*首位1*/，初始f[0]=1, f[1]=2，0位二进制可以认为全是0
        const int bitLen = sizeof(num) * 8;
        vector<int> f(bitLen);
        f[0] = 1, f[1] = 2;
        for (int i = 2; i < bitLen; i++) {
            f[i] = f[i-1] + f[i-2];
        }
        
        int count = 0;
        for (int i = bitLen - 1; i >= 0; i--) {
            if (num & (1 << i)) { // 第i位为1
                count += f[i];
                if (num & (1 << (i+1))) { // 第i+1位为1
                    return count;
                }
            }
        }
        return count + 1; // count是<n的数，1是n本身        
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
