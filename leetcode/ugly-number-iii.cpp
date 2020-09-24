//
//  ugly-number-iii
//  https://leetcode.com/problems/ugly-number-iii/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        // 猜第n小的a,b,c倍数为m，m的取值范围为[0, 2*10^9]
        // 设二分搜索条件enough(m)表示"<=m的a,b,c倍数的个数"count>=n
        // 而 count = m/a +m/b +m/c -m/lcm(a,b) 
        //         -m/lcm(b,c) -m/lcm(c,a) +m/lcm(a,b,c)
        long lcm_ab = a / __gcd(a, b) * (long)b;
        long lcm_bc = b / __gcd(b, c) * (long)c;
        long lcm_ca = c / __gcd(c, a) * (long)a;
        long lcm_abc = a / __gcd((long)a, lcm_bc) * lcm_bc;
        long l = 0, u = 2 * 1e9;
        while (l + 1 < u) {
            long m = l + (u - l) / 2;
            int count = m / a + m / b + m / c - m / lcm_ab 
                    - m / lcm_bc - m / lcm_ca + m / lcm_abc;         
            if (count >= n) {
                u = m;
            } else {
                l = m;
            }
        }
        return u;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
