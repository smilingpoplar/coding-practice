//
//  palindrome-permutation-ii
//  https://leetcode.com/problems/palindrome-permutation-ii/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> generatePalindromes(string s) {
        unordered_map<char, int> mp;
        int oddCnt = 0;
        for (char c : s) {
            mp[c]++;
            if (mp[c] % 2 == 1) oddCnt++;
            else oddCnt--;
        }
        if (odd > 1) return {};

        char mid;
        string half;
        for (auto &e : mp) {
            if (e.second % 2 == 1) mid = e.first;
            else half += string(e.second / 2, e.first);
        }
        
        vector<string> ans;
        permute(half, 0, mid, ans);
        return ans;
    }
    
    void permute(string &half, int idx, const string &mid, vector<string> &ans) {
        if (idx == half.size()) {
            ans.push_back(half + mid + string(half.rbegin(), half.rend()));
            return;
        }
        
        for (int i = idx; i < half.size(); i++) {
            if (i > idx && half[i] == half[i-1]) continue; // 确保相同元素只选第一个

            swap(half[i], half[idx]);
            permute(idx + 1, half, mid, ans);
            swap(half[i], half[idx]);
        }
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
