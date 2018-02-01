//
//  powx-n
//  https://leetcode.com/problems/powx-n/
//
//  Created by smilingpoplar on 15/6/15.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        long nl = n; // 防止INT_MIN取负溢出
        if (nl < 0) {
            x = 1 / x;
            nl = -nl;
        }
        
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
