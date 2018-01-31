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
        unordered_map<char, int> mp; // char=>lastIdx
        int longest = 0;
        for (int i = 0, start = 0; i < s.size(); i++) {
            if (mp.find(s[i]) != mp.end() && mp[s[i]] >= start) {
                start = mp[s[i]] + 1;                
            } else {
                longest = max(longest, i - start + 1);
            }
            mp[s[i]] = i;
        }
        return longest;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.lengthOfLongestSubstring("abbaab");
    
    return 0;
}
