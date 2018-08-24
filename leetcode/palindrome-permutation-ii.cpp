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
        
        // 最多1个奇数，奇数个那个字符放mid
        string half, mid;
        for (auto &e : mp) {
            if (e.second % 2 == 1) {
                mid = string(1, e.first);
            }
            half += string(e.second / 2, e.first);
        }
        vector<string> ans;
        permute(0, half, mid, ans);
        return ans;
    }
    
    void permute(int idx, string &half, const string &mid, vector<string> &ans) {
        if (idx == half.size()) {
            ans.push_back(half + mid + string(half.rbegin(), half.rend()));
            return;
        }
        
        unordered_set<char> seen;
        for (int i = idx; i < half.size(); i++) {
            if (seen.count(half[i])) continue;
            seen.insert(half[i]);
            
            swap(half[i], half[idx]);
            permute(idx + 1, half, mid, ans);
            swap(half[i], half[idx]);
        }
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
