//
//  number-of-1-bits
//  https://leetcode.com/problems/number-of-1-bits/
//
//  Created by smilingpoplar on 15/6/17.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n) {
            n &= n - 1;
            count++;
        }
        return count;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.hammingWeight(11);
 
    return 0;
}