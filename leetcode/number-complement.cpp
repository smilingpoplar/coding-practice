//
//  number-complement
//  https://leetcode.com/problems/number-complement/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int findComplement(int num) {
        int mask = ~0;
        while (mask & num) mask <<= 1;
        return ~mask & ~num;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
