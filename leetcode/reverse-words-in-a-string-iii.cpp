//
//  reverse-words-in-a-string-iii
//  https://leetcode.com/problems/reverse-words-in-a-string-iii/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int left = 0;
        int i = 0;
        while (i < s.size()) {
            while (s[i] == ' ' && i < s.size()) ++i;
            left = i;
            while (s[i] != ' ' && i < s.size()) ++i;
            reverse(s, left, i - 1);
        }
        return s;
    }
    
    void reverse(string &s, int i, int j) {
        while (i < j) {
            char c = s[i];
            s[i] = s[j];
            s[j] = c;
            ++i;
            --j;
        }
    }
        
};

int main(int argc, const char * argv[]) {    
    return 0;
}
