//
//  valid-palindrome
//  https://leetcode.com/problems/valid-palindrome/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = (int)s.size() - 1;
        while (i < j) {
            while (i < j && !isalnum(s[i])) i++;
            while (i < j && !isalnum(s[j])) j--;
            if (tolower(s[i]) != tolower(s[j])) return false;
            i++, j--;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.isPalindrome("A man, a plan, a canal: Panama");
    
    return 0;
}
