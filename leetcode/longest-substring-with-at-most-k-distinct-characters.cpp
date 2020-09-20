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
        vector<int> cnt(128, 0);
        int distinct = 0, ans = 0;
        // 有效窗口：distinct <= k
        for (int hi = 0, lo = 0; hi < s.size(); hi++) {
            if (cnt[s[hi]]++ == 0) distinct++;
            while (distinct > k) {
                if (--cnt[s[lo]] == 0) distinct--;
                lo++;
            }
            ans = max(ans, hi - lo + 1);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
