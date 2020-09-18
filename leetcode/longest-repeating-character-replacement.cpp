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
        int maxCnt = 0, ans = 0;
        for (int lo = 0, hi = 0; hi < s.size(); hi++) {
            // 每一步都尝试将窗口长度推到极限 maxCnt+k
            maxCnt = max(maxCnt, ++count[s[hi]]);
            while (hi - lo + 1 > maxCnt + k) {
                count[s[lo]]--;
                lo++;
            }
            // 用maxCnt不能保证当前窗口都有效，但不影响结果，
            // 可以保证最长有效窗口一定计算到
            ans = max(ans, hi - lo + 1);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
