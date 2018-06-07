//
//  valid-parenthesis-string
//  https://leetcode.com/problems/valid-parenthesis-string/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int lo = 0, hi = 0; // 左括号剩余数的可能取值范围[lo, hi]
        for (char c : s) {
            lo += (c == '(') ? 1 : -1;
            hi += (c == ')') ? -1 : 1;
            // 在这过程中，hi一旦小于0，[lo, hi]没有>=0的有效值，串无效；
            // 而lo小于0的值可以舍弃，lo=max(lo, 0)
            if (hi < 0) return false;
            lo = max(lo, 0);
        }
        // 最终[lo,hi]含0串才有
        return lo == 0;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
