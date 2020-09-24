//
//  concatenated-words
//  https://leetcode.com/problems/concatenated-words/
//
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
        // 设dp[i]表示s[i..]可分割成一个或多个单词，
        // dp[i] = any{ dp[j] && isWord(s[i..j-1]) }，0<=i<j<=N
        // 初始dp[N]=true
        const int N = s.size();
        vector<bool> dp(N + 1, false);
        dp[N] = true;
        for (int i = N - 1; i >= 0; i--) {
            for (int j = i + 1; j <= N && !dp[i]; j++) {
                dp[i] = dp[j] && dict.count(s.substr(i, j - i));
            }
        }
        return dp[0];
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
