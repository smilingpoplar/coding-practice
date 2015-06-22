//
//  word-search-ii
//  https://leetcode.com/problems/word-search-ii/
//
//  Created by smilingpoplar on 15/5/27.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class TrieNode {
public:
    TrieNode() : next(26, NULL) { }
    vector<TrieNode *> next;
    string word;
};

class Trie {
public:
    Trie() : root(new TrieNode()) { }
    ~Trie() { deleteNode(root); }
    
    void insert(const string &word) {
        auto node = root;
        for (char c : word) {
            int index = c - 'a';
            if (!node->next[index]) node->next[index] = new TrieNode();
            node = node->next[index];
        }
        node->word = word;
    }
    
    TrieNode *root;
private:
    void deleteNode(TrieNode *node) {
        for (auto child : node->next) {
            if (child) deleteNode(child);
        }
        delete node;
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
        if (board.empty()) return {};
        const int M = (int)board.size();
        const int N = (int)board[0].size();
        vector<vector<bool>> visited(M, vector<bool>(N, false));
        Trie wordsToFind;
        for (const auto &word : words) {
            wordsToFind.insert(word);
        }
        vector<string> result;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                dfs(board, i, j, visited, wordsToFind.root, result);
            }
        }
        return result;
    }
private:
    void dfs(const vector<vector<char>> &board, int i, int j, vector<vector<bool>> &visited,
             TrieNode *trieNode, vector<string> &result) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) return;
        if (visited[i][j]) return;
        visited[i][j] = true;
        auto node = trieNode->next[board[i][j] - 'a'];
        if (node) {
            if (!node->word.empty()) {
                result.push_back(node->word);
                node->word.clear(); // 不再搜索这个词
            }
            dfs(board, i - 1, j, visited, node, result);
            dfs(board, i + 1, j, visited, node, result);
            dfs(board, i, j - 1, visited, node, result);
            dfs(board, i, j + 1, visited, node, result);
        }
        visited[i][j] = false;
    }
};

int main(int argc, const char * argv[]) {
    vector<vector<char>> board = {
        {'o','a','a','n'},
        {'e','t','a','e'},
        {'i','h','k','r'},
        {'i','f','l','v'},
    };
    vector<string> words = {
        "oath","pea","eat","rain",
    };
    Solution solution;
    auto result = solution.findWords(board, words);
    for (const auto &word : result) {
        cout << word << " ";
    }
    
    return 0;
}
