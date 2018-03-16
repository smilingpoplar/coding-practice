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
        unordered_map<string, int> mp; // reverse=>pos
        for (int i = 0; i < words.size(); i++) {
            string reverse = string(words[i].rbegin(), words[i].rend());
            mp[reverse] = i;
        }
        
        vector<vector<int>> ans;
        for (int i = 0; i < words.size(); i++) {
            const string &word = words[i];
            for (int j = 0; j <= word.size(); j++) {
                // left|right + reverse_left
                if (isPalindrome(word, j, word.size() - 1)) {
                    string left = word.substr(0, j);
                    if (mp.count(left) && mp[left] != i) {
                        ans.push_back({i, mp[left]});                    
                    }
                }
                
                // abc|"" + cba => {0,1}
                // abc + ""|cba => {0,1}
                // 这两种情况结果重复，需排除掉一种
                if (j == 0) continue;

                // reverse_right + left|right
                if (isPalindrome(word, 0, j - 1)) {
                    string right = word.substr(j);
                    if (mp.count(right) && mp[right] != i) {
                        ans.push_back({mp[right], i});                     
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
