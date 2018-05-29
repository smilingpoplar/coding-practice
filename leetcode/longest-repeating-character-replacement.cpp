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
        int maxSameTillNow = 0; // 至今为止的有效窗口中最大字符数，最长有效窗口是 maxSameTillNow + k
        int start = 0, end = 0, ans = 0;
        while (end < s.size()) {
            maxSameTillNow = max(maxSameTillNow, ++count[s[end]]);
            end++;
            if (end - start > maxSameTillNow + k) { // 若是无效窗口、再移动start使窗口有效
                count[s[start]]--;
                start++;
            }
            ans = max(ans, end - start);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
