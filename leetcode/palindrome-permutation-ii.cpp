//
//  palindrome-permutation-ii
//  https://leetcode.com/problems/palindrome-permutation-ii/
//
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
        
        unordered_set<char> seen; // 防止相同元素再次交换
        for (int i = idx; i < half.size(); i++) {
            if (seen.count(half[i])) continue;
            seen.insert(half[i]);
            
            swap(half[i], half[idx]);
            permute(half, idx + 1, odd, ans);
            swap(half[i], half[idx]);
        }
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
