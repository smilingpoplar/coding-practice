//
//  longest-substring-with-at-least-k-repeating-characters
//  https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {
        return rLongestSubstring(s, 0, s.size(), k);
    }
    
    int rLongestSubstring(const string &s, int start, int end, int k) {
        // 分治法：统计各字符次数，次数<k的不能出现在最长子串中，可从字符处切成两个子问题
        if (end - start < k) return 0;
        vector<int> count(26, 0);
        for (int i = start; i < end; i++) {
            count[s[i] - 'a']++;
        }
        for (int i = 0; i < count.size(); i++) {
            if (0 < count[i] && count[i] < k) { // 需要条件：0 < count[i]
                auto pos = s.find(i + 'a', start);
                int left = rLongestSubstring(s, start, pos, k);
                int right = rLongestSubstring(s, pos + 1, end, k);
                return max(left, right);
            }
        }
        return end - start;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
