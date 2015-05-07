//
//  longest-substring-without-repeating-characters.cpp
//  https://leetcode.com/problems/longest-substring-without-repeating-characters/
//
//  Created by smilingpoplar on 15/5/4.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // 若子串含重复字符，则父串也含重复字符，设s[start,i)是无重复子串
        // 1. 若s[i]是重复字符，则新的无重复子串：s[lastIndex[s[i]]+1,i+1)
        // 2. 若s[i]不是重复字符，则新的无重复子串：s[start,i+1)
        const size_t ASCII_SIZE = 256;
        vector<int> lastIndex(ASCII_SIZE, -1); // 每个字符最后出现的位置
        int longest = 0;
        for (int i = 0, start = 0; i < s.size(); i++) {
            if (lastIndex[s[i]] >= start) {
                start = lastIndex[s[i]] + 1;
            } else {
                longest = max(longest, i + 1 - start);
            }
            lastIndex[s[i]] = i;
        }
        
        return longest;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.lengthOfLongestSubstring("abbaab");
    
    return 0;
}
