//
//  reverse-bits
//  https://leetcode.com/problems/reverse-bits/
//
//  Created by smilingpoplar on 15/6/18.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

/*
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        for (int i = 0; i < 32; i++) {
            ans = (ans << 1) | (n & 1);
            n >>= 1;
        }
        return ans;
    }
};
*/

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        // 分治，所有小组内交换前半段和后半段
        // 比如n是uint8_t，初始len=8，mask=11111111
        // 所有组内对半分并交换：
        // 1. 算出对应所有组内后半段的mask：len >>= 1; mask ^= mask << len;
        // 2. 将所有组内前半段后移并用mask取出、后半段前移并用~mask取出
        //  第1轮：mask=00001111，~mask=11110000
        //  第2轮：mask=00110011，~mask=11001100
        //  第3轮：mask=01010101，~mask=10101010
        int len = sizeof(n) * 8;
        uint32_t mask = ~0;
        while (len > 1) {
            len >>= 1;
            mask ^= mask << len; // 算mask是关键
            n = ((n >> len) & mask) | ((n << len) & ~mask);
        }
        return n;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.reverseBits(43261596); // 964176192

    return 0;
}