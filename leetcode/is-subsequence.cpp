//
//  is-subsequence
//  https://leetcode.com/problems/is-subsequence/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

/*
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        for (int j = 0; j < t.size() && i < s.size(); j++) { // 在t中搜索s
            if (s[i] == t[j]) i++;
        }
        return i == s.size();
    }
};
*/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        // follow up，预处理t，记录个字母出现的位置列表
        vector<vector<int>> pos(26);
        for (int i = 0; i < t.size(); i++) {
            pos[t[i] - 'a'].push_back(i);
        }
        
        int lastIdx = -1;
        for (char c : s) {
            auto &list = pos[c - 'a'];
            auto it = upper_bound(list.begin(), list.end(), lastIdx);
            if (it == list.end()) return false;
            lastIdx = *it;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
