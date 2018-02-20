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
    // 广义图搜索可以找到一条最短路径，不能找到所有最短路径：
    // 1. 顶点进队列时进行标记
    // 2. 顶点出队列时更新回溯用的搜索树
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        queue<string> queue;
        queue.push(start);
        unordered_set<string> visited;
        visited.insert(start); // 1. 顶点进队列时进行标记
        
        int level = 0;
        while (!queue.empty()) {
            level++;
            size_t levelSize = queue.size();
            for (size_t i = 0; i < levelSize; i++) { // 按层遍历
                auto word = queue.front();
                queue.pop();
                // 2. 顶点出队列时更新回溯用的搜索树：这里不需要
                
                auto words = nextWords(word, end, dict);
                for (const auto &nextWord : words) {
                    if (visited.find(nextWord) == visited.end()) {
                        queue.push(nextWord);
                        visited.insert(nextWord); // 1. 顶点进队列时进行标记
                        if (nextWord == end) return level + 1;
                    }
                }
            }
        }
        
        return 0;
    }
    
    /*
    // 双队列写法
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        unordered_set<string> currentLevel, nextLevel;
        currentLevel.insert(start);
        
        unordered_set<string> visited;
        int level = 0;
        while (!currentLevel.empty()) {
            level++;
            // 先将本层全部置为已访问，防止同层之间互相指向
            for (const auto &word : currentLevel) {
                visited.insert(word);
            }
            for (const auto &word : currentLevel) {
                auto words = nextWords(word, end, dict);
                for (const auto &nextWord : words) {
                    if (visited.find(nextWord) == visited.end()) {
                        nextLevel.insert(nextWord);
                        if (nextWord == end) return level + 1;
                    }
                }
            }
            currentLevel.clear();
            swap(currentLevel, nextLevel);
        }
        
        return 0;
    }
    */
    
private:
    unordered_set<string> nextWords(const string &word, const string &end, const unordered_set<string> &dict) {
        unordered_set<string> result;
        for (size_t i = 0; i < word.size(); i++) {
            string newWord = word;
            for (char c = 'a'; c <= 'z'; c++) {
                if (newWord[i] != c) {
                    swap(c, newWord[i]);
                    
                    if (dict.find(newWord) != dict.end() || newWord == end) {
                        result.insert(newWord);
                    }
                    
                    swap(c, newWord[i]);
                }
            }
        }
        return result;
    }
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
