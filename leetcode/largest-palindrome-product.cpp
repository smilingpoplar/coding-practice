//
//  largest-palindrome-product
//  https://leetcode.com/problems/largest-palindrome-product/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int largestPalindrome(int n) {
        if (n == 1) return 9;
        // 穷举两个n位数构成的回文，看它能否分解成两个n位数相乘
        int minNum = pow(10, n-1), maxNum = minNum * 10 - 1;
        for (int i = maxNum; i >= minNum; i--) {
            long pali = getPalindrome(i);
            // 因子j和pali/j：maxNum >= j >= pali/j >= minNum
            for (long j = maxNum; j * j >= pali; j--) {
                if (pali % j == 0 && j * minNum <= pali) {
                    return pali % 1337;
                }
            }
        }
        return -1;
    }
    
    long getPalindrome(int x) {
        string s = to_string(x);
        string pali = s + string(s.rbegin(), s.rend());
        return stol(pali);
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
