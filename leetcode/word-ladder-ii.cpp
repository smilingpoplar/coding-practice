//
//  word-ladder-ii.cpp
//  https://leetcode.com/problems/word-ladder-ii/
//
//  Created by smilingpoplar on 15/4/29.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        unordered_set<string> currentLevel, nextLevel;
        currentLevel.insert(start);
        
        unordered_set<string> visited;
        unordered_map<string, unordered_set<string>> parents;
        bool found = false;
        while (!currentLevel.empty()) {
            // 先将本层全部置为已访问，防止同层之间互相指向
            for (const auto &word : currentLevel) {
                visited.insert(word);
            }
            for (const auto &word : currentLevel) {
                auto words = nextWords(word, end, dict);
                for (const auto &nextWord : words) {
                    if (visited.count(nextWord) <= 0) {
                        nextLevel.insert(nextWord);
                        parents[nextWord].insert(word);
                        if (nextWord == end) found = true;
                    }
                }
            }
            currentLevel.clear();
            swap(currentLevel, nextLevel);
            // BFS时如果找到一条最短路径，那么所有最短路径一定都在这一层，不再考虑下一层
            if (found) break;
        }
        
        return generatePaths(end, start, parents);
    }
    
private:
    unordered_set<string> nextWords(const string &word, const string &end, const unordered_set<string> &dict) {
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
    
    vector<vector<string>> generatePaths(const string &word, const string &start, unordered_map<string, unordered_set<string>> &searchTree) {
        vector<vector<string>> result;
        vector<string> path;
        generatePaths(word, start, searchTree, path, result);
        return result;
    }
    
    void generatePaths(const string &word, const string &start, unordered_map<string, unordered_set<string>> &searchTree,
                       vector<string> &path, vector<vector<string>> &result) {
        path.push_back(word);
        if (word == start) {
            result.push_back(path);
            reverse(result.back().begin(), result.back().end());
        } else {
            for (const auto &prev : searchTree[word]) {
                generatePaths(prev, start, searchTree, path, result);
            }
        }
        path.pop_back();
    }
};

int main(int argc, const char * argv[]) {
    string beginWord = "hit";
    string endWord = "cog";
    unordered_set<string> wordDict = { "hot","dot","dog","lot","log" };
    
    Solution solution;
    auto ladders = solution.findLadders(beginWord, endWord, wordDict);
    for (const auto &ladder : ladders) {
        for (const auto &word : ladder) {
            cout << word << " ";
        }
        cout << endl;
    }
    
    return 0;
}
