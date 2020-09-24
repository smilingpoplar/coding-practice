//
//  valid-palindrome-ii
//  https://leetcode.com/problems/valid-palindrome-ii/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        const int N = s.size();
        int i = 0, j = N - 1;
        while (i <= j && s[i] == s[j]) { ++i; --j; }
        if (i > j) return true;
        
        return isPalindrome(s, i + 1, j) || isPalindrome(s, i, j - 1);
    }
    
    bool isPalindrome(const string &s, int i, int j) {
        while (i <= j) {
            if (s[i] != s[j]) return false;
            ++i; --j;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
