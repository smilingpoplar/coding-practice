//
//  1-bit-and-2-bit-characters
//  https://leetcode.com/problems/1-bit-and-2-bit-characters/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        // 0开头的只能解析1位、1开头的只能解析2位
        // 从头解析，看能否解析到达N-1位
        const int N = bits.size();
        int idx = 0;
        while (idx < N - 1) {
            if (bits[idx] == 0) idx += 1;
            else idx += 2;
        }
        return idx == N - 1;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
