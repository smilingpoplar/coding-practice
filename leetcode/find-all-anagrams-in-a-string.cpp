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
        int start = 0;
        // 每次移动一步end：若是有效窗口、再移动start缩小至无效窗口
        for (int end = 0; end < s.size(); end++) {
            if (--count[s[end]] == 0) distinct--;
            while (distinct == 0) { // 有效窗口
                if (end - start + 1 == p.size()) ans.push_back(start);
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
