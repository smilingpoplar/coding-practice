//
//  palindrome-pairs
//  https://leetcode.com/problems/palindrome-pairs/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        // 将w1分成s1=w1[0..cut)、s2=w1[cut..)两段，几种情况：
        // 1. w1[0..cut)是回文，w2是w1[cut..)反转，w2+w1是回文
        //    cut=0时，w2是w1反转，w2+w1是回文
        //    cut=len时，w1是回文，w2是空串，w2+w1是回文
        // 2. w1[cut..)是回文，w2是w1[0..cut)反转，w1+w2是回文
        //    cut=0时，w1是回文，w2是空串，w1+w2是回文
        //    cut=len时，w2是w1反转，w1+w2是回文
        //    
        // 若w1、w2一个回文一个空串，遍历到w1时贡献w1+w2和w2+w1，遍历到w2时没贡献；
        // 若w1、w2互为反转，遍历到w1时贡献w1+w2和w2+w1，遍历到w2时又贡献w2+w1和w1+w2，这就重复了。
        // 
        const int N = words.size();
        unordered_map<string, int> mp; // reverse=>pos
        for (int i = 0; i < N; i++) {
            string reverse = string(words[i].rbegin(), words[i].rend());
            mp[reverse] = i;
        }
        
        vector<vector<int>> ans;
        for (int i = 0; i < N; i++) {
            const string &word = words[i];
            const int len = word.size();
            for (int cut = 0; cut <= len; cut++) {
                // 情况1
                if (isPalindrome(word, 0, cut - 1)) {
                    string s2 = word.substr(cut);
                    if (mp.count(s2) && mp[s2] != i) {
                        ans.push_back({mp[s2], i});                     
                    }
                }
                if (cut == len) continue;
                // 情况2
                if (isPalindrome(word, cut, len - 1)) {
                    string s1 = word.substr(0, cut);
                    if (mp.count(s1) && mp[s1] != i) {
                        ans.push_back({i, mp[s1]});                    
                    }
                }
            }
        }
        return ans;
    }

    bool isPalindrome(const string &s, int left, int right) {
        while (left < right) {
            if (s[left++] != s[right--]) return false;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
