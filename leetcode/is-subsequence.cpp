//
//  is-subsequence
//  https://leetcode.com/problems/is-subsequence/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

/*
class Solution {
public:
    bool isSubsequence(string s, string t) {
        // 在t中找s
        int is = 0, it = 0;
        while (it < t.size() && is < s.size()) {
            if (s[is] == t[it]) is++;
            it++;
        }
        return is == s.size();
    }
};
*/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        // follow up，预处理t，记录每个字母出现的位置列表
        vector<vector<int>> pos(26);
        for (int i = 0; i < t.size(); i++) {
            pos[t[i] - 'a'].push_back(i);
        }

        int lastIdx = -1;
        for (char c : s) {  // 应在各字母的位置列表穿梭前进
            auto &list = pos[c - 'a'];
            auto it = upper_bound(list.begin(), list.end(), lastIdx);
            if (it == list.end()) return false;
            lastIdx = *it;
        }
        return true;
    }
};

int main(int argc, const char *argv[]) {
    return 0;
}
