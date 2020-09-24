//
//  backspace-string-compare
//  https://leetcode.com/problems/backspace-string-compare/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int i = (int)S.size() - 1, j = (int)T.size() - 1;
        while (true) {
            backScan(S, i), backScan(T, j);
            if (i < 0 || j < 0) return i == j;
            if (S[i] != T[j]) return false;
            i--, j--;
        }
    }
    
    // 从后往前比较，遇到'#'时skip++
    void backScan(const string &S, int &i) {
        int skip = 0;
        while (i >= 0 && (S[i] == '#' || skip > 0)) { // S[i]!=# && skip==0 时停下
            if (S[i] == '#') skip++;
            else skip--;    
            i--;
        }
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
