//
//  valid-word-abbreviation
//  https://leetcode.com/problems/valid-word-abbreviation/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0, j = 0;
        while (i < abbr.size()) {
            if (isalpha(abbr[i])) {
                if (abbr[i++] != word[j++]) return false;
            } else { // digit
                if (abbr[i] == '0') return false;
                int num = 0;
                while (i < abbr.size() && isdigit(abbr[i])) {
                    num = num * 10 + abbr[i++] - '0';
                }
                j += num;
            }
        }
        return j == word.size();
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
