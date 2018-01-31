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
        vector<string> partition;
        search(s, 0, partition, ans);
        return ans;
    }

    void search(const string &s, int start, vector<string> &partition, vector<vector<string>> &ans) {
        if (start == s.size()) {
            ans.push_back(partition);
            return;
        }
        for (int i = start; i < s.size(); i++) {
            if (!isPalindrome(s, start, i)) continue;
            partition.push_back(s.substr(start, i - start + 1));
            search(s, i + 1, partition, ans);
            partition.pop_back();
        }
    }
    
    bool isPalindrome(const string &s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) return false;
            ++left;
            --right;
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