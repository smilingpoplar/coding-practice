//
//  word-ladder.cpp
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
    int ladderLength(string begin, string end, unordered_set<string> &dict) {
        queue<string> queue;
        queue.push(begin);
        visited.insert(begin); // 把顶点放入队列时进行标记
        
        int level = 0;
        while (!queue.empty()) {
            level++;
            size_t levelSize = queue.size();
            for (size_t i = 0; i < levelSize; i++) { // 按层遍历
                auto word = queue.front();
                queue.pop();
                // ... 这里不需要：把顶点移出队列时更新回溯用的搜索树

                if (word == end) return level;
                
                auto adjacences = adjacentWords(word, end, dict);
                for (auto adjacence : adjacences) {
                    if (visited.count(adjacence) <= 0) {
                        queue.push(adjacence);
                        visited.insert(adjacence); // 把顶点放入队列时进行标记
                    }
                }
            }
        }
        
        return 0;
    }
    
private:
    unordered_set<string> adjacentWords(const string &word, const string &end, unordered_set<string> &dict) {
        unordered_set<string> result;
        for (size_t i = 0; i < word.size(); i++) {
            string newWord = word;
            for (char c = 'a'; c <= 'z'; c++) {
                if (newWord[i] != c) {
                    swap(c, newWord[i]);
                    
                    if (dict.count(newWord) > 0 || newWord == end) {
                        result.insert(newWord);
                    }
                    
                    swap(c, newWord[i]);
                }
            }
        }
        return result;
    }
private:
    unordered_set<string> visited;
};

int main(int argc, const char * argv[]) {
    string beginWord = "hit";
    string endWord = "cog";
    unordered_set<string> wordDict = { "hot", "dot", "dog", "lot", "log" };
    
    Solution solution;
    int ladders = solution.ladderLength(beginWord, endWord, wordDict);
    cout << ladders << endl;
    
    return 0;
}
