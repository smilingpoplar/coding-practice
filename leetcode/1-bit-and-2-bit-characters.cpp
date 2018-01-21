//
//  1-bit-and-2-bit-characters
//  https://leetcode.com/problems/1-bit-and-2-bit-characters/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        // 扫描前进，看能否通过前n-1位，停在最后1位上
        int i = 0;
        while (i < bits.size() - 1) {
            if (bits[i] == 0) {
                i += 1;
            } else {
                i += 2;
            }
        }
        return i == bits.size() - 1;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
