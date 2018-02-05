//
//  word-break.cpp
//  https://leetcode.com/problems/word-break/
//
//  Created by smilingpoplar on 15/5/1.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // 设dp[i]表示s[0..i-1]是否可分成一个或多个词，
        // dp[i] = dp[j] && isWord(s[j..i-1])，0<=j<i
        // 初始设 dp[0]=true
        unordered_set<string> dict;
        for (auto &s : wordDict)
            dict.insert(s);

        const int N = s.size();
        vector<bool> dp(N + 1, false);
        dp[0] = true;
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[N];
    }
};

int main(int argc, const char * argv[]) {
    vector<string> wordDict = {"leet", "code"};
    Solution solution;
    cout << solution.wordBreak("leetcode", wordDict);
    
    return 0;
}
