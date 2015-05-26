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
        // 伸缩窗口法，不变式：s[i,j]中含t
        if (s.empty() || s.size() < t.size()) return "";
        unordered_map<char, int> tCount;
        for (char c : t) ++tCount[c];
        
        int i = 0;
        int found = 0;
        int minWidth = INT_MAX;
        int foundI = 0;
        unordered_map<char, int> sCount;
        for (int j = 0; j < s.size(); ++j) { // 伸展尾指针
            ++sCount[s[j]];
            if (sCount[s[j]] <= tCount[s[j]]) ++found;
            if (found == t.size()) { // 收缩头指针
                while (tCount[s[i]] == 0 || sCount[s[i]] > tCount[s[i]]) {
                    --sCount[s[i]];
                    ++i;
                }
                // s[i,j]中含t
                if (j - i + 1 < minWidth) {
                    minWidth = j - i + 1;
                    foundI = i;
                }
                // 头指针再缩一格
                --sCount[s[i]];
                ++i;
                --found;
            }
        }
        return minWidth == INT_MAX ? "" : s.substr(foundI, minWidth);
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.minWindow("cabwefgewcwaefgcf", "cae");
    
    return 0;
}
