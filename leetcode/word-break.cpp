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
    bool wordBreak(string s, unordered_set<string>& dict) {
        // 动态规划，设ok[i]表示s[0,i)可break，则存在j(0<=j<i)使得s[0,i)可break成s[0,j)子问题和s[j,i)单词
        const size_t N = s.size();
        vector<bool> ok(N + 1, false);
        ok[0] = true;
        for (size_t i = 1; i <= N; i++) {
            for (size_t j = 0; j < i; j++) {
                if (ok[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                    ok[i] = true;
                    break;
                }
            }
        }
        return ok[N];
    }
};

int main(int argc, const char * argv[]) {
    unordered_set<string> wordDict = {"leet", "code"};
    Solution solution;
    cout << solution.wordBreak("leetcode", wordDict);
    
    return 0;
}
