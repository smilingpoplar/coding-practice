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
        int distinct = count.size();
        
        vector<int> ans;
        // 每次hi移动一步：若是有效窗口、lo再移动至无效窗口
        for (int lo = 0, hi = 0; hi < s.size(); hi++) {
            if (--count[s[hi]] == 0) distinct--;
            while (distinct == 0) { // 有效窗口
                if (hi - lo + 1 == p.size()) ans.push_back(lo);
                if (count[s[lo]]++ == 0) distinct++;
                lo++;
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
