//
//  check-if-word-is-valid-after-substitutions
//  https://leetcode.com/problems/check-if-word-is-valid-after-substitutions/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool isValid(string S) {
        // 用栈，从左到右扫，遇到c时弹出末尾的b和a
        string stk;
        for (char c : S) {
            if (c == 'c') {
                if (stk.empty() || stk.back() != 'b') return false;
                stk.pop_back();
                if (stk.empty() || stk.back() != 'a') return false;
                stk.pop_back();
            } else {
                stk.push_back(c);
            }
        }
        return stk.empty();
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
