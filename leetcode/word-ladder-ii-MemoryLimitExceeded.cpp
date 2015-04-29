//
//  word-ladder-ii.cpp
//  https://leetcode.com/problems/word-ladder-ii/
//
//  Created by smilingpoplar on 15/4/29.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <unordered_set>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        queue<string> queue;
        queue.push(start);
        unordered_set<string> visited;
        visited.insert(start); // 把顶点放入队列时进行标记
        
        unordered_map<string, vector<string>> searchTree;
        while (!queue.empty()) {
            // BFS时如果找到一条最短路径，那么所有最短路径一定都在这一层，下一层的不再考虑，所以使用按层遍历
            bool found = false;
            size_t levelSize = queue.size();
            for (size_t i = 0; i < levelSize; i++) {
                auto word = queue.front();
                queue.pop();
                // ... 把顶点移出队列时更新回溯用的搜索树：这里改成在进队列时更新
                
                auto words = nextWords(word, end, dict);
                for (auto next : words) {
                    if (next == end) {
                        found = true;
                        searchTree[next].push_back(word); // 在进队列时更新回溯用的搜索树
                    } else if (visited.count(next) <= 0) {
                        queue.push(next);
                        visited.insert(next); // 把顶点放入队列时进行标记
                        searchTree[next].push_back(word); // 在进队列时更新回溯用的搜索树
                    }
                }
            }
            if (found) break;
        }
        
        return generatePaths(end, start, searchTree);
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
    
    vector<vector<string>> generatePaths(const string &word, const string &start, unordered_map<string, vector<string>> &searchTree) {
        vector<vector<string>> result;
        vector<string> path;
        generatePaths(word, start, searchTree, path, result);
        return result;
    }
    
    void generatePaths(const string &word, const string &start, unordered_map<string, vector<string>> &searchTree,
                       vector<string> &path, vector<vector<string>> &result) {
        path.push_back(word);
        if (word == start) {
            result.push_back(path);
            reverse(result.back().begin(), result.back().end());
        } else {
            for (auto prev : searchTree[word]) {
                generatePaths(prev, start, searchTree, path, result);
            }
        }
        path.pop_back();
    }
};

int main(int argc, const char * argv[]) {
    string beginWord = "a";
    string endWord = "c";
    unordered_set<string> wordDict = { "a", "b", "c" };
    
    Solution solution;
    auto ladders = solution.findLadders(beginWord, endWord, wordDict);
    for (auto ladder : ladders) {
        for (auto word : ladder) {
            cout << word << " ";
        }
        cout << endl;
    }
    
    return 0;
}
