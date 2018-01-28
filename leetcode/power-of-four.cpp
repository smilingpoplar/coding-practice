//
//  power-of-four
//  https://leetcode.com/problems/power-of-four/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfFour(int num) {
        return (num >= 1)
            && ((num & (num - 1)) == 0)   // 二进制只有1个1s
            && ((num & 0x55555555) != 0); // 且这个1s只能出现在...01010101这些位
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
