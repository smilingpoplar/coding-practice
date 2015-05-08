//
//  bitwise-and-of-numbers-range
//  https://leetcode.com/problems/bitwise-and-of-numbers-range/
//
//  Created by smilingpoplar on 15/5/8.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        // "范围与"的结果是：首尾两数的二进制公共前缀
        // 因为非公共前缀部分肯定是0xxxx和1xxxx的形式，存在中间数10000使这部分"范围与"后变为00000
        int shift = 0;
        while (m != n) {
            m >>= 1;
            n >>= 1;
            ++shift;
        }
        return m << shift;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.rangeBitwiseAnd(5, 7);
    
    return 0;
}
