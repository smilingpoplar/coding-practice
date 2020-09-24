//
//  convert-a-number-to-hexadecimal
//  https://leetcode.com/problems/convert-a-number-to-hexadecimal/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";
        const string HEX = "0123456789abcdef";
        string ans;
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
