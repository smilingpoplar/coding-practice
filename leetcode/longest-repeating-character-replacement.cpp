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
        int maxCntEndingHere = 0;
        int start = 0, end = 0, ans = 0;
        while (end < s.size()) {
            maxCntEndingHere = max(maxCntEndingHere, ++count[s[end]]);
            end++;
            // 不变式：滑动窗口s[start,end)维护着长为 当前最长有效窗口长maxCntEndingHere+k 的一个窗口
            // 注意，该滑动窗口本身可以不是有效窗口
            // 尝试扩展end（end++），若扩展无效则start--，相当于窗口右移
            if (end - start > maxCntEndingHere + k) {
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
