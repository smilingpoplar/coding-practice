//
//  palindrome-pairs
//  https://leetcode.com/problems/palindrome-pairs/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        // 将w1分成w1[0..cut)、w1[cut..)两段，0<=cut<=len，两种情况：
        // 1. w1[0..cut)是回文，w1[cut..)是w2反转，w2+w1是回文
        // 2. w1[cut..)是回文，w1[0..cut)是w2反转，w1+w2是回文
        // 若w1、w2互为反转，比如abc、cba，
        //  abc|null + cba，处理单词abc、cut=len，返回{0,1}
        //  abc + null|cba，处理单词cba、cut=0，  返回{0,1}
        // 这就重复了，这时用cut>0或cut<len去掉一种重复。

        const int N = words.size();
        unordered_map<string, int> mp; // reverse=>idx
        for (int i = 0; i < N; i++) {
            string reverse(words[i].rbegin(), words[i].rend());
            mp[reverse] = i;
        }
        
        vector<vector<int>> ans;
        for (int i = 0; i < N; i++) {
            const string &word = words[i];
            const int len = word.size();
            for (int cut = 0; cut <= len; cut++) {
                // case 1
                if (isPalindrome(word, 0, cut - 1)) {
                    string s2 = word.substr(cut);
                    if (mp.count(s2) && mp[s2] != i) {
                        ans.push_back({mp[s2], i});                     
                    }
                }
                // case 2
                if (isPalindrome(word, cut, len - 1)) {
                    string s1 = word.substr(0, cut);
                    if (mp.count(s1) && mp[s1] != i && cut < len) { // 用cut<len去重
                        ans.push_back({i, mp[s1]});                    
                    }
                }
            }
        }
        return ans;
    }

    bool isPalindrome(const string &s, int lo, int hi) {
        while (lo < hi) {
            if (s[lo++] != s[hi--]) return false;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
