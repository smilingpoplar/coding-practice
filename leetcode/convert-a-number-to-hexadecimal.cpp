//
//  convert-a-number-to-hexadecimal
//  https://leetcode.com/problems/convert-a-number-to-hexadecimal/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";
        string ans;
        string HEX = "0123456789abcdef";
        unsigned x = num;
        while (x) {
            ans.push_back(HEX[x & 0x0f]);
            x >>= 4;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
