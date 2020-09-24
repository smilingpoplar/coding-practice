//
//  poor-pigs
//  https://leetcode.com/problems/poor-pigs/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        // 一只猪可不吃食或者a次试毒，有(a+1)种选择，作(a+1)进制的一位。
        // b只猪就是共b位。总共可试毒(a+1)^b桶。
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
