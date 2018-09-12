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
        // 负数也可以处理
        long rev = 0;
        while (x) {
            rev = rev * 10 + x % 10;
            if (rev < INT_MIN || rev > INT_MAX) return 0;
            x /= 10;
        }
        return rev;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.reverse(1003);
    
    return 0;
}