//
//  word-break-ii
//  https://leetcode.com/problems/word-break-ii/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <unordered_set>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        dict.insert(wordDict.begin(), wordDict.end());
        unordered_map<int, vector<string>> memo; // idx => sentences
        return search(s, 0, dict, memo);
    }
    
    // 为s[idx..]生成句子
    vector<string> search(const string &s, int idx, unordered_set<string>& dict,
                          unordered_map<int, vector<string>> &memo) {
        if (memo.count(idx)) return memo[idx];
        
        vector<string> ans;
        for (int i = idx; i < s.size(); i++) {
            // 分成单词s[idx..i]、子问题s[i+1..]
            auto word = s.substr(idx, i - idx + 1);
            if (!dict.count(word)) continue;
            if (i == s.size() - 1) {
                ans.push_back(word); // 句子只有一个词
            } else {
                auto suffixes = search(s, i + 1, dict, memo);
                for (auto &suffix : suffixes) {
                    ans.push_back(word + " " + suffix); 
                }                
            }
        }
        
        memo[idx] = ans;
        return ans;
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
