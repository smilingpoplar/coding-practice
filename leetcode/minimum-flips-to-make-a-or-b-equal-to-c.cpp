//
//  minimum-flips-to-make-a-or-b-equal-to-c
//  https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int aorb = a | b, diff = aorb ^ c;
        int ans = 0;
        for (int i = 0; i < 32; i++){
            unsigned mask = 1 << i;
            if (diff & mask) { // 第i位不同
                // ai==0 && bi==0 => 则ci==1，flip 1位
                // ai==1 && bi==1 => 则ci==0，flip 2位
                // ai==1 || bi==1 => 则ci==0，flip 1位
                ans += ((a & mask) && (b & mask)) ? 2 : 1;
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
