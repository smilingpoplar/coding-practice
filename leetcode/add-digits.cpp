//
//  add-digits
//  https://leetcode.com/problems/add-digits/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int addDigits(int num) {
        // 参考：https://en.wikipedia.org/wiki/Digital_root
        // 因为 10^i % 9 == 1，所以 num % 9 == sum(digit*10^i) % 9 == sum(digit) % 9
        if (num == 0) return 0;
        if (num % 9 == 0) return 9;
        return num % 9;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.addDigits(38);
    
    return 0;
}
