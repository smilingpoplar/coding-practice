//
//  longest-substring-without-repeating-characters
//  https://leetcode.com/problems/longest-substring-without-repeating-characters/
//
//  Created by smilingpoplar on 15/5/4.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

/*
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> count;
        int repeat = 0, ans = 0;
        for (int lo = 0, hi = 0; hi < s.size(); hi++) {
            if (++count[s[hi]] >= 2) repeat++;
            while (repeat > 0) {
                if (count[s[lo]]-- >= 2) repeat--;
                lo++;
            }
            ans = max(ans, hi - lo + 1);
        }
        return ans;
    }
};
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp; // 用map记录滑动窗口内的char=>lastIdx
        int ans = 0;
        for (int lo = 0, hi = 0; hi < s.size(); hi++) {
            if (mp.count(s[hi]) && mp[s[hi]] >= lo) { // s[hi]重复出现且有效
                lo = mp[s[hi]] + 1;
            }
            ans = max(ans, hi - lo + 1);
            mp[s[hi]] = hi;
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.lengthOfLongestSubstring("abbaab");
    
    return 0;
}
