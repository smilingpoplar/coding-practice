//
//  reverse-vowels-of-a-string
//  https://leetcode.com/problems/reverse-vowels-of-a-string/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        set<char> vowels = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int i = 0, j = (int)s.size() - 1;
        while (i < j) {
            while (i < j && !vowels.count(s[i])) i++;
            while (i < j && !vowels.count(s[j])) j--;
            if (i < j) swap(s[i], s[j]);
            i++, j--;
        }
        return s;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
