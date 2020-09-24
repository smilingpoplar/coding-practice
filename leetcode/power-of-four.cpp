//
//  power-of-four
//  https://leetcode.com/problems/power-of-four/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfFour(int num) {
        // 二进制仅有一个1，且这个1出现在...010101这些位
        return num > 0 && (num & (num - 1)) == 0 && (num & 0x55555555) != 0;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
