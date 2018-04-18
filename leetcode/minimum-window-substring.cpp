//
//  minimum-window-substring
//  https://leetcode.com/problems/minimum-window-substring/
//
//  Created by smilingpoplar on 15/5/26.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || s.size() < t.size()) return "";
        unordered_map<char, int> count;
        for (char c : t) count[c]++;
        int distinct = count.size();
        
        int minWidth = INT_MAX, ansStart;
        int start = 0, end = 0;
        while (end < s.size()) {
            if (--count[s[end]] == 0) distinct--;
            end++;
            while (distinct == 0) {
                if (end - start < minWidth) {
                    minWidth = end - start;
                    ansStart = start;
                }
                if (count[s[start]]++ == 0) distinct++;
                start++;
            }
        }
        return minWidth != INT_MAX ? s.substr(ansStart, minWidth) : "";
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.minWindow("cabwefgewcwaefgcf", "cae");
    
    return 0;
}
