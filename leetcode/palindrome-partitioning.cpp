//
//  palindrome-partitioning
//  https://leetcode.com/problems/palindrome-partitioning/
//
//  Created by smilingpoplar on 15/6/3.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> parts;
        search(s, 0, parts, ans);
        return ans;
    }

    void search(const string &s, int idx, vector<string> &parts, vector<vector<string>> &ans) {
        const int N = s.size();
        if (idx == N) {
            ans.push_back(parts);
            return;
        }
        // 尝试割下s[idx..i]
        for (int i = idx; i < N; i++) {
            if (!isPalindrome(s, idx, i)) continue;
            parts.push_back(s.substr(idx, i - idx + 1));
            search(s, i + 1, parts, ans);
            parts.pop_back();
        }
    }
    
    bool isPalindrome(const string &s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    auto result = solution.partition("aab");
    for (const auto &partition : result) {
        for (const auto &palindrome : partition) {
            cout << palindrome << " ";
        }
        cout << endl;
    }
    
    return 0;
}