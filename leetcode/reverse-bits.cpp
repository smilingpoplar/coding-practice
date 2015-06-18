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
        uint32_t result = 0;
        for (int i = 0; i < 32; ++i) {
            result |= (n & 1) << (31 - i);
            n >>= 1;
        }
        return result;
    }
};
*/

class Solution {
public:
    Solution() {
        // 多次查询优化，缓存reverseBits(uint8_t n)的结果
        for (int i = 0; i < 256; ++i) {
            uint8_t n = (uint8_t)i;
            n = (n & 0b11110000) >> 4 | (n & 0b00001111) << 4;
            n = (n & 0b11001100) >> 2 | (n & 0b00110011) << 2;
            n = (n & 0b10101010) >> 1 | (n & 0b01010101) << 1;
            cache[i] = n;
        }
    }

    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        uint8_t *p = (uint8_t *)&n, *q = (uint8_t *)&result;
        const int byteCount = 4;
        for (int i = 0; i < byteCount; ++i) {
            q[byteCount - 1 - i] = cache[p[i]];
        }
        return result;
    }
private:
    uint8_t cache[256];
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.reverseBits(43261596); // 964176192

    return 0;
}