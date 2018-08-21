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
        int distinct = 0, ans = 0;
        for (int lo = 0, hi = 0; hi < s.size(); hi++) {
            if (cnt[s[hi]]++ == 0) distinct++;
            while (distinct > k) { // 若是无效窗口、再移动lo缩小窗口
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
