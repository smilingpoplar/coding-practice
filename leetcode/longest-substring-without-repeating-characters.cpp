//
//  longest-substring-without-repeating-characters
//  https://leetcode.com/problems/longest-substring-without-repeating-characters/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

/*
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        const int N = s.size();
        unordered_map<char, int> cnt;
        int ans = 0;
        for (int hi = 0, lo = 0; hi < N; hi++) {
            cnt[s[hi]]++;
            while (cnt[s[hi]] > 1) {
                cnt[s[lo]]--;
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
        const int N = s.size();
        unordered_map<char, int> mp;  // char=>lastIdx
        int ans = 0;
        for (int hi = 0, lo = 0; hi < N; hi++) {
            if (mp.count(s[hi]) && mp[s[hi]] >= lo) {  // s[hi]重复出现且在窗口内
                lo = mp[s[hi]] + 1;
            }
            ans = max(ans, hi - lo + 1);
            mp[s[hi]] = hi;
        }
        return ans;
    }
};

int main(int argc, const char* argv[]) {
    Solution solution;
    cout << solution.lengthOfLongestSubstring("abbaab");

    return 0;
}
