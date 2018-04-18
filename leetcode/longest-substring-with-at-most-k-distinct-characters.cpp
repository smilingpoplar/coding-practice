//
//  longest-substring-with-at-most-k-distinct-characters
//  https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        // 滑动窗口法
        vector<int> cnt(128, 0);
        int distinct = 0, start = 0, ans = 0;
        for (int end = 0; end < s.size(); end++) {
            if (cnt[s[end]]++ == 0) distinct++;
            while (distinct > k) { // 不满足条件时缩小窗口
                if (--cnt[s[start]] == 0) distinct--;
                start++;
            }
            ans = max(ans, end - start + 1);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
