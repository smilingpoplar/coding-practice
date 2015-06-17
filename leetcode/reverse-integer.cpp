//
//  reverse-integer
//  https://leetcode.com/problems/reverse-integer/
//
//  Created by smilingpoplar on 15/6/17.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        if (x == INT_MIN) return 0; // -2147483648，反转将溢出
        int sign = 1;
        if (x < 0) {
            sign = -1;
            x = -x;
        }
        
        int r = 0;
        while (x) {
            if (r > (INT_MAX - x % 10) / 10) return 0; // > INT_MAX，溢出
            r = r * 10 + x % 10;
            x /= 10;
        }
        return sign * r;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.reverse(1003);
    
    return 0;
}