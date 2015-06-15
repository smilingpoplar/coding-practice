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
        if (n < 0) {
            if (n == INT_MIN) return 1 / (x * myPow(x, INT_MAX));
            return 1 / myPow(x, -n);
        }
        
        double result = 1;
        while (n) {
            if (n & 1) result *= x;
            x *= x;
            n >>= 1;
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.myPow(2, -3);

    return 0;
}
