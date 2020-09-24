//
//  longest-substring-with-at-most-two-distinct-characters
//  https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int k = 2; // at most 2
        unordered_map<int, int> cnt; // char=>count
        int ans = 0;
        for (int hi = 0, lo = 0; hi < s.size(); hi++) {
            if (cnt[s[hi]]++ == 0) k--;
            while (k < 0) {
                if (--cnt[s[lo]] == 0) k++;
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
