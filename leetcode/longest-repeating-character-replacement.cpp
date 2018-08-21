//
//  longest-repeating-character-replacement
//  https://leetcode.com/problems/longest-repeating-character-replacement/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> count;
        int maxCntTillNow = 0; // 迄今为止窗口中的最大字符数
        int ans = 0;
        for (int lo = 0, hi = 0; hi < s.size(); hi++) {
            maxCntTillNow = max(maxCntTillNow, ++count[s[hi]]);
            // 替换发生后，有效窗口最长 <= maxCntTillNow + k
            if (hi - lo + 1 > maxCntTillNow + k) { // 若是无效窗口、再移动lo使窗口有效
                count[s[lo]]--;
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
