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
        // 先移动end找到合法窗口，再移动start缩小窗口
        int start = 0, end = 0;
        while (end < s.size()) {
            if (count.find(s[end]) != count.end() && --count[s[end]] == 0) distinct--;
            end++;
            while (distinct == 0) { // 合法窗口
                if (end - start == p.size()) {
                    ans.push_back(start);
                }
                if (count.find(s[start]) != count.end() && ++count[s[start]] == 1) distinct++;
                start++;
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
