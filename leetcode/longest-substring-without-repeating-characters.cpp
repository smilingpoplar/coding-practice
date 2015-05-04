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
        // 若子串含重复字符，则父串一定也含重复字符，单个子问题决定父问题，用贪心法
        // 这跟dp不同，dp是单个子问题影响父问题，不足以决定父问题
        const size_t ASCII_SIZE = 256;
        vector<int> lastIndex(ASCII_SIZE, -1); // 每个字符最后出现的位置
        int longest = 0;
        // s[start,i]是无重复字符子串
        for (int i = 0, start = 0; i < s.size(); i++) {
            if (lastIndex[s[i]] >= start) {
                start = lastIndex[s[i]] + 1;
            }
            longest = max(longest, i - start + 1);

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
