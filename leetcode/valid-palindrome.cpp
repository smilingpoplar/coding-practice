//
//  valid-palindrome
//  https://leetcode.com/problems/valid-palindrome/
//
//  Created by smilingpoplar on 15/6/15.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        int i = 0;
        int j = (int)s.size() - 1;
        while (i < j) {
            while (i < j && !isalnum(s[i])) ++i;
            while (i < j && !isalnum(s[j])) --j;
            if (i < j && s[i] != s[j]) return false;
            ++i;
            --j;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.isPalindrome("A man, a plan, a canal: Panama");
    
    return 0;
}
