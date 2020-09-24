//
//  power-of-two
//  https://leetcode.com/problems/power-of-two/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.isPowerOfTwo(16);
    
    return 0;
}
