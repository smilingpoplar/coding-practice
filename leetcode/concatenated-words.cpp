//
//  concatenated-words
//  https://leetcode.com/problems/concatenated-words/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string &a, const string &b){
            return a.size() < b.size();
        });
        
        vector<string> ans;
        unordered_set<string> shorterWords;
        for (const string &word : words) {
            if (wrodBreak(word, shorterWords)) {
                ans.push_back(word);
            }
            shorterWords.insert(word);
        }
        return ans;
    }
    
    bool wrodBreak(const string &s, unordered_set<string> &dict) {
        if (dict.empty()) return false;
        // 设dp[i]表示s[i..N-1]可分成一个多个单词，0<=i<=N
        // dp[i] = isWord(s[i..k-1]) && dp[k]，i<k<=N
        // 初始设dp[N]=true
        const int N = s.size();
        vector<bool> dp(N + 1, false);
        dp[N] = true;
        for (int i = N - 1; i >= 0; i--) {
            for (int k = N; k > i; k--) {
                if (dp[k] && dict.count(s.substr(i, k - i))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[0];
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
