//
//  longest-uncommon-subsequence-ii
//  https://leetcode.com/problems/longest-uncommon-subsequence-ii/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int findLUSlength(vector<string> &strs) {
        // 最长，且不是其他串的子序列
        unordered_map<string, int> cnt;
        for (string &s : strs)
            cnt[s]++;

        sort(begin(strs), end(strs), [](const string &a, const string &b) {
            return a.size() > b.size();
        });
        for (int i = 0; i < strs.size(); i++) {
            if (cnt[strs[i]] > 1) continue;
            int j = 0;
            while (j < i && !isSubsequence(strs[i], strs[j]))
                j++;
            if (j == i) return strs[i].size();
        }
        return -1;
    }

    bool isSubsequence(const string &sub, const string &str) {
        int idx = 0;
        for (char c : str) {
            if (idx < sub.size() && sub[idx] == c) idx++;
            if (idx == sub.size()) return true;
        }
        return false;
    }
};

int main(int argc, const char *argv[]) {
    return 0;
}
