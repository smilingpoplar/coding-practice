//
//  add-digits
//  https://leetcode.com/problems/add-digits/
//
//  Created by smilingpoplar on 15/8/21.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int addDigits(int num) {
        // 参考：https://en.wikipedia.org/wiki/Digital_root
        // 除了 dr(0)=0, dr(n)=9 if n%9==0，dr(n)=n%9 otherwise；通式 dr(n) = 1+(n-1)%9
        return 1 + (num - 1) % 9;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.addDigits(38);
    
    return 0;
}
