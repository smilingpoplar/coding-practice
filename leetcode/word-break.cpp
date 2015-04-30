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
        // 动态规划，设 possible[i]表示s[0,i)这个子串可以break成
        const size_t N = s.size();
        vector<bool> possible(N + 1, false);
        possible[0] = true;
        for (size_t i = 1; i <= N; i++) {
            // 看s[0,j)和s[j,i)是否都是合格子串
            for (size_t j = 0; j < i; j++) {
                if (possible[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                    possible[i] = true;
                    break;
                }
            }
        }
        return possible[N];
    }
};

int main(int argc, const char * argv[]) {
    unordered_set<string> wordDict = {"leet", "code"};
    Solution solution;
    cout << solution.wordBreak("leetcode", wordDict);
    
    return 0;
}
