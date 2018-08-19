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
        // 二进制只能有一个1，且这个1只能出现在...010101这些位
        return num >= 1 && (num & (num - 1)) == 0 && (num & 0x55555555) != 0;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
