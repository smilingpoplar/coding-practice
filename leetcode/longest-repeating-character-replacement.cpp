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
        int maxCountInWin = 0;
        int ans = 0;
        int start = 0, end = 0;
        while (end < s.size()) {
            maxCountInWin = max(maxCountInWin, ++count[s[end]]);
            end++;
            // 滑动窗口中需要替换的字符数为winSize-maxCountInWin
            while (end - start - maxCountInWin > k) {
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
