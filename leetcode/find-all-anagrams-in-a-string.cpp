//
//  find-all-anagrams-in-a-string
//  https://leetcode.com/problems/find-all-anagrams-in-a-string/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> count;
        for (char c : p) count[c]++;
        int distinct = count.size(); // 要找多少个不同的字符
        
        vector<int> ans;
        // 每次移动一步end：若找到有效窗口、再移动start使窗口无效
        int start = 0, end = 0;
        while (end < s.size()) {
            if (--count[s[end]] == 0) distinct--;
            end++;
            while (distinct == 0) { // 有效窗口
                if (end - start == p.size()) {
                    ans.push_back(start);
                }
                if (count[s[start]]++ == 0) distinct++;
                start++;
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
