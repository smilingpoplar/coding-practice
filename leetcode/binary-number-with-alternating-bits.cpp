//
//  binary-number-with-alternating-bits
//  https://leetcode.com/problems/binary-number-with-alternating-bits/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n) {
        int last = n & 1;
        n >>= 1;
        while (n) {
            if ((n & 1) == last) return false;
            last = n & 1;
            n >>= 1;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
