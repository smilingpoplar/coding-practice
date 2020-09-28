//
//  unique-substrings-in-wraparound-string
//  https://leetcode.com/problems/unique-substrings-in-wraparound-string/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int findSubstringInWraproundString(string p) {
        // 找以各个字母结尾的最长子串长
        // 比如以d结尾的最长子串bcd长3，它就贡献了d、cd、bcd三个子串
        vector<int> endsWith(26);
        int len = 0;
        for (int i = 0; i < p.size(); i++) {
            if (i > 0 && (p[i] == p[i-1] + 1 || p[i] == p[i-1] - 25)) len++;
            else len = 1;
            int charIdx = p[i] - 'a';
            endsWith[charIdx] = max(endsWith[charIdx], len);
        }

        return accumulate(begin(endsWith), end(endsWith), 0);
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
