//
//  palindrome-number
//  https://leetcode.com/problems/palindrome-number/
//
//  Created by smilingpoplar on 15/6/17.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int reverse = 0;
        int tmpX = x;
        while (tmpX) {
            reverse = reverse * 10 + tmpX % 10;
            tmpX /= 10;
        }
        // 溢出的话变成负数，返回false
        return x == reverse;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.isPalindrome(10);
    
    return 0;
}