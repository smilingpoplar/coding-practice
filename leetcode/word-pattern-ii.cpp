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
        // 回溯法
        unordered_map<char, string> mp; // letter => mappingStr
        unordered_set<string> st; // 防止mappingStr多次匹配
        return match(pattern, 0, str, 0, mp, st);
    }
    
    bool match(const string &pattern, int i, const string &str, int j,
              unordered_map<char, string> &mp, unordered_set<string> &st) {
        if (i == pattern.size() && j == str.size()) return true; // 两个都匹配完
        if (i == pattern.size() || j == str.size()) return false; // 只一个匹配完
        
        char patternChar = pattern[i];
        if (mp.find(patternChar) != mp.end()) {
            auto mappingStr = mp[patternChar];
            if (!startsWith(mappingStr, str, j)) return false;
            return match(pattern, i + 1, str, j + mappingStr.size(), mp, st);
        }
        
        // 回溯，尝试匹配str[j..k]
        for (int k = j; k < str.size(); k++) {
            auto mappingStr = str.substr(j, k - j + 1);
            if (st.find(mappingStr) != st.end()) continue;
            mp[patternChar] = mappingStr;
            st.insert(mappingStr);
            if (match(pattern, i + 1, str, k + 1, mp, st)) return true;
            mp.erase(patternChar);
            st.erase(mappingStr);
        }
        return false;
    }
    
    bool startsWith(const string &prefix, const string &str, int pos) {
        if (prefix.size() + pos > str.size()) return false;
        for (int i = 0; i < prefix.size(); i++) {
            if (prefix[i] != str[i + pos]) return false;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
