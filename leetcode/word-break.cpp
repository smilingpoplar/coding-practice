//
//  word-break
//  https://leetcode.com/problems/word-break/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // 设dp[i]表示s[i..]可分割成一个或多个单词，
        // dp[i] = any{ dp[j] && isWord(s[i..j-1]) }，0<=i<j<=N
        // 初始dp[N]=true
        unordered_set<string> dict;
        for (auto &s : wordDict)
            dict.insert(s);

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
    vector<string> wordDict = {"leet", "code"};
    Solution solution;
    cout << solution.wordBreak("leetcode", wordDict);
    
    return 0;
}
