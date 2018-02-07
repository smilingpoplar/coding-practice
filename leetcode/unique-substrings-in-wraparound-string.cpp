//
//  unique-substrings-in-wraparound-string
//  https://leetcode.com/problems/unique-substrings-in-wraparound-string/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int findSubstringInWraproundString(string p) {
        // 找p中以各个字母结尾的最长子串长。比如以d结尾的最长子串长3，它就贡献了d、cd、bcd三个子串
        vector<int> longest(26);
        int length;
        for (int i = 0; i < p.size(); i++) {
            if (i > 0 && (p[i] == p[i-1] + 1 || p[i] == p[i-1] - 25)) length++;
            else length = 1;
            int idx = p[i] - 'a';
            longest[idx] = max(longest[idx], length);
        }
        int ans = 0;
        for (int i = 0; i < longest.size(); i++) ans += longest[i];
        return ans;        
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
