//
//  valid-parenthesis-string
//  https://leetcode.com/problems/valid-parenthesis-string/
//
//  Created by smilingpoplar on 18/01/18.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        return check(s, 0, 0);
    }
    
    // s[index..]且有lefts个左括号剩余
    bool check(const string &s, int index, int lefts) {
        if (index == s.size() && lefts == 0) return true;
        if (lefts < 0) return false;
        if (s[index] == '(') return check(s, index+1, lefts+1);
        if (s[index] == ')') return check(s, index+1, lefts-1);
        if (s[index] == '*') return check(s, index+1, lefts) || check(s, index+1, lefts+1) || check(s, index+1, lefts-1);
        return false;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
