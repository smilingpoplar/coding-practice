//
//  poor-pigs
//  https://leetcode.com/problems/poor-pigs/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        // 一只猪可不吃食或者m次试毒，有(m+1)种选择，作为(m+1)进制的一位。
        // n只猪就是n位。总共可试毒(m+1)^n桶。
        int base = minutesToTest / minutesToDie + 1;
        int power = 0;
        while (pow(base, power) < buckets)
            power++;
        return power;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
