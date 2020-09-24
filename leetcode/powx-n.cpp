//
//  powx-n
//  https://leetcode.com/problems/powx-n/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        long nl = n; // 防止INT_MIN取负时溢出
        if (nl < 0) {
            x = 1 / x;
            nl = -nl;
        }
        
        // 取幂的二进制最后一位，累乘
        double ans = 1;
        while (nl) {
            if (nl & 1) ans *= x;
            x *= x;
            nl >>= 1;
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.myPow(2, -3);

    return 0;
}
