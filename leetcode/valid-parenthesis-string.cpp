//
//  valid-parenthesis-string
//  https://leetcode.com/problems/valid-parenthesis-string/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        // '*' 可表示 '('、')'、空串，设多出的左括号数leftDiff的范围为[lo, hi]。
        // 1. 遇到'('，左括号多1，lo++, hi++；
        // 2. 遇到')'，左括号少1，lo--, hi--；
        // 3. 遇到'*'，它可以是'('、空串、')'，[lo, hi]内的每个值都可-1、+0、+1，整体扩张lo--, hi++。
        // 综上，遇到'('时lo++、其他lo--；遇到')'时hi--，其他hi++。 
        int lo = 0, hi = 0;
        for (char c : s) {
            lo += (c == '(') ? 1 : -1;
            hi += (c == ')') ? -1 : 1;
            // 在扫描过程中，一旦hi<0，leftDiff<0，串无效
            if (hi < 0) return false;
            // 而lo<0的部分可以直接丢弃
            lo = max(lo, 0);
        }
        // 最终能够leftDiff==0，串才有效
        return lo == 0;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
