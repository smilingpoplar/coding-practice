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
        for (auto &word : words) {
            if (wordBreak(word, shorterWords)) {
                ans.push_back(word);
            }
            shorterWords.insert(word);
        }
        return ans;
    }

    bool wordBreak(const string &s, unordered_set<string> &dict) {
        if (dict.empty()) return false;
        // 设dp[i]表示s[0..i-1]可分成一个或多个单词，
        // dp[i] = dp[j] && isWord(s[j..i-1])，0<=j<i
        // 初始设 dp[0]=true
        const int N = s.size();
        vector<bool> dp(N + 1, false);
        dp[0] = true;
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && dict.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[N];
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
