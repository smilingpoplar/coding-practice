//
//  isomorphic-strings
//  https://leetcode.com/problems/isomorphic-strings/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, char> mapping;
        unordered_map<char, char> rMapping;
        for (int i = 0; i < s.size(); i++) {
            if (mapping.count(s[i]) && mapping[s[i]] != t[i]) return false; // 一对多
            if (rMapping.count(t[i]) && rMapping[t[i]] != s[i]) return false; // 多对一
            mapping[s[i]] = t[i];
            rMapping[t[i]] = s[i];
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.isIsomorphic("bar", "foo") << endl; // 0
    cout << solution.isIsomorphic("paper", "title") << endl; // 1
    
    return 0;
}
