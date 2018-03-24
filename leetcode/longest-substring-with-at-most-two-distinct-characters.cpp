//
//  longest-substring-with-at-most-two-distinct-characters
//  https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        // 滑动窗口法
        vector<int> cnt(128, 0);
        int distinct = 0, start = 0, ans = 0;
        for (int end = 0; end < s.size(); end++) {
            if (++cnt[s[end]] == 1) distinct++;
            while (distinct > 2) { // 不满足条件时缩小窗口
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
