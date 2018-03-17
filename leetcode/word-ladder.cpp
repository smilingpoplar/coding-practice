//
//  word-ladder
//  https://leetcode.com/problems/word-ladder/
//
//  Created by smilingpoplar on 15/4/28.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict;
        for (auto &word : wordList) {
            dict.insert(word);
        }
        queue<string> Q;
        Q.push(beginWord);
        unordered_set<string> visited;
        visited.insert(beginWord);
        
        int level = 0;
        while (!Q.empty()) {
            level++;
            for (int sz = Q.size(); sz > 0; sz--) { // 按层遍历
                auto word = Q.front(); Q.pop();
                
                auto nextWords = getNextWords(word, endWord, dict);
                for (auto &nextWord : nextWords) {
                    if (!visited.count(nextWord)) {
                        Q.push(nextWord);
                        visited.insert(nextWord); // 要在进队列时设visited[]，这样取出时同层词都设置过，避免向同层词扩展
                        if (nextWord == endWord) return level + 1;
                    }
                }
            }
        }
        return 0;
    }

    /*
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict;
        for (auto &word : wordList) {
            dict.insert(word);
        }
        
        unordered_set<string> currLevel;
        currLevel.insert(beginWord);
        unordered_set<string> visited;

        int level = 0;
        while (!currLevel.empty()) {
            level++;
            // 将同层词的visited[]全部设置，避免向同层词扩展
            for (auto &word : currLevel) {
                visited.insert(word);
            }
            unordered_set<string> nextLevel;
            for (auto &word : currLevel) {
                auto nextWords = getNextWords(word, endWord, dict);
                for (auto &nextWord : nextWords) {
                    if (!visited.count(nextWord)) {
                        nextLevel.insert(nextWord);
                        if (nextWord == endWord) return level + 1;
                    }
                }
            }
            swap(nextLevel, currLevel);
        }
        return 0;
    }
    */
    
    unordered_set<string> getNextWords(const string &word, 
                const string &endWord, const unordered_set<string> &dict) {
        unordered_set<string> ans;
        for (size_t i = 0; i < word.size(); i++) {
            string newWord(word);
            for (char c = 'a'; c <= 'z'; c++) {
                if (newWord[i] == c) continue;

                swap(c, newWord[i]);                    
                if (dict.count(newWord)) ans.insert(newWord);
                swap(c, newWord[i]);
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
