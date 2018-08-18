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
        // 设f[n]表示n位二进制中无连续1s的有多少个
        // 根据最高位是0还是1，f[n] = f[n-1]/*最高位0*/ + f[n-2]/*最高位1*/
        // 初始f[1]=2、f[2]=3，推得f[0]=1
        const int N = sizeof(num) * 8;
        vector<int> f(N);
        f[0] = 1, f[1] = 2;
        for (int n = 2; n < N; n++) { // 不含符号位
            f[n] = f[n-1] + f[n-2];
        }
        
        // 求[0,num)间无连续1s的数有多少个，从num的最高位i=N-2看起（不含符号位），
        // 一位位地拼入prefix，prefix = bit[N-2...i]位来自num、后面位全0的数。
        // 累加[lastPrefix, prefix)间无连续1s的个数，就是在分区间统计[0,num)。
        // 比如num=23，(10111)。就分区统计了二进制区间[0,10000), [10000,10100), [10100,10110), [10110,10111)。
        // 怎么统计分区间[lastPrefix, prefix)？
        // 若prefix的第i位为1，考虑第i位为0、bit[i-1..0]位任意的取值区间，贡献f[i]个的无连续1s的数。
        // 若prefix的第i位为0，prefix==lastPrefix，区间为空可以略过。
        int count = 0;
        int prebit = 0; // 初始时是符号位
        for (int i = N - 2; i >= 0; i--) {
            if (num & (1 << i)) { // 第i位为1
                count += f[i];
                if (prebit) return count; // 遇到连续的1s
                prebit = 1;
            } else {
                prebit = 0;
            }
        }
        // 已求[0,num)间的个数，再加上num自身
        return count + 1;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
