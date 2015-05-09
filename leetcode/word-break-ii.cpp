//
//  word-break-ii.cpp
//  https://leetcode.com/problems/word-break-ii/
//
//  Created by smilingpoplar on 15/5/1.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <unordered_set>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& dict) {
        // 动态规划，设ok(i)表示s[0,i)可break，breakAt(i,j)表示s[0,i)可在j处break成s[0,j)和s[j,i)
        // (s[0,j)是子问题，s[j,i)是单词，0<=i<=N, 0<=j<i)
        const size_t N = s.size();
        vector<bool> ok(N + 1, false);
        vector<vector<bool>> breakAt(N + 1, vector<bool>(N, false));
        
        ok[0] = true;
        for (size_t i = 1; i <= N; i++) {
            for (size_t j = 0; j < i; j++) {
                if (ok[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                    ok[i] = true;
                    breakAt[i][j] = true;
                }
            }
        }
        
        return generateSentences(s, breakAt);
    }
private:
    vector<string> generateSentences(const string &s, const vector<vector<bool>> &breakAt) {
        vector<string> result;
        vector<string> path;
        generateSentences(s.size(), s, breakAt, path, result);
        return result;
    }
    
    // 为s[0,i)生成句子
    void generateSentences(size_t i, const string &s, const vector<vector<bool>> &breakAt, vector<string> &path, vector<string> &result) {
        if (i == 0) { // 终止条件
            auto sentence = generateSentence(path);
            result.push_back(sentence);
            return;
        }
        
        for (size_t j = 0; j < i; j++) {
            if (breakAt[i][j]) {
                path.push_back(s.substr(j, i - j));
                generateSentences(j, s, breakAt, path, result);
                path.pop_back();
            }
        }
    }
    
    string generateSentence(const vector<string> &path) {
        if (path.empty()) return "";
        const int N = (int)path.size();
        ostringstream oss;
        oss << path[N - 1];
        for (int i = N - 2; i >= 0; i--) {
            oss << " " << path[i];
        }
        return oss.str();
    }
};

int main(int argc, const char * argv[]) {
    unordered_set<string> wordDict = {"cat", "cats", "and", "sand", "dog"};
    Solution solution;
    auto allSentences = solution.wordBreak("catsanddog", wordDict);
    for (const auto &sentence : allSentences) {
        cout << sentence << endl;
    }
    
    return 0;
}
