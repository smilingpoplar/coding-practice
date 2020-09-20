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
        int maxCnt = 0;
        int lo, hi;
        for (lo = 0, hi = 0; hi < s.size(); hi++) {
            // 每一步都尝试将窗口长度推到极限 maxCnt+k
            // 不收缩的滑动窗口，窗口不符合条件时整体右移一步
            maxCnt = max(maxCnt, ++count[s[hi]]);
            if (hi - lo + 1 > maxCnt + k) {
                count[s[lo]]--;
                lo++;
            }
        }
        return hi - lo;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
