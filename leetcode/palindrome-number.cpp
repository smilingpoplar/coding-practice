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
        // 看x反转后是否仍为x，反转后溢出的情况仍适用
        int r = 0;
        int tmpX = x;
        while (tmpX) {
            r = r * 10 + tmpX % 10;
            tmpX /= 10;
        }
        return r == x;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.isPalindrome(10);
    
    return 0;
}