//
//  word-pattern-ii
//  https://leetcode.com/problems/word-pattern-ii/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool wordPatternMatch(string pattern, string str) {
        unordered_map<char, string> mp; // c => mappingStr
        unordered_set<string> st; // 防止mappingStr多次匹配
        return match(pattern, 0, str, 0, mp, st);
    }
    
    bool match(const string &pattern, int pi, const string &str, int si,
              unordered_map<char, string> &mp, unordered_set<string> &st) {
        const int M = pattern.size(), N = str.size();
        if (pi == M && si == N) return true;  // 两个都匹配完
        if (pi == M || si == N) return false; // 只一个匹配完
        
        char c = pattern[pi];
        if (mp.count(c)) {
            auto mappingStr = mp[c];
            if (!startsWith(mappingStr, str, si)) return false;
            return match(pattern, pi + 1, str, si + mappingStr.size(), mp, st);
        }
        
        // 回溯法，尝试给c匹配str[si..i]
        for (int i = si; i < str.size(); i++) {
            auto mappingStr = str.substr(si, i - si + 1);
            if (st.count(mappingStr)) continue;
            
            mp[c] = mappingStr;
            st.insert(mappingStr);
            if (match(pattern, pi + 1, str, i + 1, mp, st)) return true;
            mp.erase(c);
            st.erase(mappingStr);
        }
        return false;
    }
    
    // prefix和str[idx..]是否相等
    bool startsWith(const string &prefix, const string &str, int idx) {
        if (idx + prefix.size() > str.size()) return false;
        for (int i = 0; i < prefix.size(); i++) {
            if (prefix[i] != str[idx + i]) return false;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
