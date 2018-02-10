//
//  hamming-distance
//  https://leetcode.com/problems/hamming-distance/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int d = x ^ y;
        int count = 0;
        while (d) {
            d &= (d - 1);
            count++;
        }
        return count;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
