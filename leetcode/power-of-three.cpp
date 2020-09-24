//
//  power-of-three
//  https://leetcode.com/problems/power-of-three/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n < 1) return false;
        while (n % 3 == 0) {
            n /= 3;
        }
        return n == 1;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
