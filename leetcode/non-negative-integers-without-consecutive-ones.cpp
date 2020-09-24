//
//  non-negative-integers-without-consecutive-ones
//  https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int findIntegers(int num) {
        // 设f[n]表示n位二进制中无连续1s的有多少个
        // 根据最高位是0还是1，f[n] = f[n-1]/*最高位0*/ + f[n-2]/*最高位1*/
        // 初始f[1]=2、f[2]=3，推得f[0]=1
        const int N = 32; // 32bit
        vector<int> f(N, 0);
        f[0] = 1, f[1] = 2;
        for (int n = 2; n < N; n++) {
            f[n] = f[n-1] + f[n-2];
        }
        
        // 求[0,num)间无连续1s的数有多少个
        // 从num的最高位i=N-2看起（不含符号位），一位位拼入prefix，prefix = bit[N-2...i]位来自num、后面位全是0的数。
        // 累加拼入num的第i位前后，新增区间[lastPrefix, prefix)内无连续1s的个数。比如num=23 (10111) 要统计
        // 新增区间[0,10000), [10000,10000), [10000,10100), [10100,10110), [10110,10111)。
        // 统计新增区间，看拼入的num第i位：
        //  若拼入的位为1，新增区间内第i位为0、bit[i-1..0]位任意，贡献f[i]个无连续1s的数；
        //  若拼入的位为0，新增区间为空。
        int count = 0;
        int prebit = 0; // 初始是符号位
        for (int i = N - 2; i >= 0; i--) {
            if (num & (1 << i)) { // 第i位为1
                count += f[i];
                if (prebit) return count; // 遇到连续的1s，提前返回
                prebit = 1;
            } else {
                prebit = 0;
            }
        }
        // 已统计[0,num)，再算上num自身
        return count + 1;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
