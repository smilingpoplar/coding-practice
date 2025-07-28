//
//  sum-of-two-integers
//  https://leetcode.com/problems/sum-of-two-integers/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        // 不用加减号，做加法
        while (b) {
            int carry = (a & b) << 1;
            a = a ^ b;
            b = carry;
        }
        return a;
    }
};

int main(int argc, const char* argv[]) {
    return 0;
}
