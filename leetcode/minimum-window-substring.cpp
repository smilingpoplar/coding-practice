//
//  minimum-window-substring
//  https://leetcode.com/problems/minimum-window-substring/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
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
        
        int minWidth = INT_MAX, ansLo;
        for (int hi = 0, lo = 0; hi < s.size(); hi++) {
            if (--count[s[hi]] == 0) distinct--;
            while (distinct == 0) { // 有效窗口
                if (hi - lo + 1 < minWidth) {
                    minWidth = hi - lo + 1;
                    ansLo = lo;
                }
                if (count[s[lo]]++ == 0) distinct++;
                lo++;
            }
        }
        return minWidth != INT_MAX ? s.substr(ansLo, minWidth) : "";
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.minWindow("cabwefgewcwaefgcf", "cae");
    
    return 0;
}
