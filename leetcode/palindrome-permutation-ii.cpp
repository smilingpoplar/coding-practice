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
        if (oddCnt > 1) return {};

        string odd, half;
        for (auto &e : mp) {
            if (e.second % 2 == 1) odd = string(1, e.first);
            half += string(e.second / 2, e.first);
        }
        
        vector<string> ans;
        permute(half, 0, odd, ans);
        return ans;
    }
    
    void permute(string &half, int idx, const string &odd, vector<string> &ans) {
        if (idx == half.size()) {
            ans.push_back(half + odd + string(half.rbegin(), half.rend()));
            return;
        }
        
        for (int i = idx; i < half.size(); i++) {
            if (i > idx && half[i] == half[i-1]) continue; // 确保相同元素只选第一个

            swap(half[i], half[idx]);
            permute(half, idx + 1, odd, ans);
            swap(half[i], half[idx]);
        }
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
