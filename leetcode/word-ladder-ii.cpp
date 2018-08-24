//
//  word-ladder-ii
//  https://leetcode.com/problems/word-ladder-ii/
//
//  Created by smilingpoplar on 15/4/29.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict;
        for (auto &word : wordList) dict.insert(word);
        
        // 分层bfs找最短路径
        unordered_set<string> currLevel;
        currLevel.insert(beginWord);
        unordered_set<string> visited;
        unordered_map<string, unordered_set<string>> prevs; // 记录词变换
        bool found = false;
        while (!currLevel.empty() && !found) {
            // 出队时设置visited[]，而不是入队时，这样允许多条变换路径；
            // 将同层词的visited[]全部设置，避免向同层词变换。
            for (auto &word : currLevel) visited.insert(word);
            
            unordered_set<string> nextLevel;
            for (auto &word : currLevel) {
                auto nextWords = getNextWords(word, endWord, dict);
                for (auto &nextWord : nextWords) {
                    if (visited.count(nextWord)) continue;
                    nextLevel.insert(nextWord);
                    prevs[nextWord].insert(word);
                    if (nextWord == endWord) found = true;
                }
            }
            swap(nextLevel, currLevel);
        }
        
        vector<vector<string>> ans;
        vector<string> path;
        genPaths(endWord, beginWord, prevs, path, ans);
        return ans;
    }
    
private:
    unordered_set<string> getNextWords(const string &word, 
                const string &endWord, const unordered_set<string> &dict) {
        unordered_set<string> ans;
        string nextWord(word);
        for (size_t i = 0; i < nextWord.size(); i++) {
            for (char c = 'a'; c <= 'z'; c++) {
                if (nextWord[i] == c) continue;

                swap(c, nextWord[i]);                    
                if (dict.count(nextWord)) ans.insert(nextWord);
                swap(c, nextWord[i]);
            }
        }
        return ans;
    }
    
    void genPaths(const string &word, const string &beginWord, 
                unordered_map<string, unordered_set<string>> &prevs,
                vector<string> &path, vector<vector<string>> &ans) {
        path.push_back(word); // 先反向存，最后reverse
        if (word == beginWord) {
            ans.push_back(vector<string>(path.rbegin(), path.rend()));
        } else {
            for (auto &p : prevs[word]) {
                genPaths(p, beginWord, prevs, path, ans);
            }
        }
        path.pop_back();
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
