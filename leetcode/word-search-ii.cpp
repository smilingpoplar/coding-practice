//
//  word-search-ii
//  https://leetcode.com/problems/word-search-ii/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    struct TrieNode {
        string word;
        vector<TrieNode *> child;
        TrieNode() : child(26, nullptr) {}
    };

    TrieNode root;
public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
        // 将单词表存成trie结构以同时搜索整个单词表，在矩阵中回溯搜索
        if (board.empty()) return {};
        const int R = board.size(), C = board[0].size();
        vector<vector<bool>> visited(R, vector<bool>(C, false));
        for (auto &word : words) {
            insertToTrie(word);
        }

        vector<string> ans;
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                search(r, c, board, visited, &root, ans);
            }
        }
        return ans;
    }

    void insertToTrie(const string &word) {
        auto p = &root;
        for (char c : word) {
            int idx = c - 'a';
            if (!p->child[idx]) p->child[idx] = new TrieNode();
            p = p->child[idx];
        }
        p->word = word;
    }

    void search(int r, int c, const vector<vector<char>> &board, 
             vector<vector<bool>> &visited, TrieNode *node, vector<string> &ans) {
        const int R = board.size(), C = board[0].size();
        if (r < 0 || r >= R || c < 0 || c >= C || visited[r][c]) return;
        // 回溯法，在trie中搜索board[r][c]
        int idx = board[r][c] - 'a';
        auto p = node->child[idx];
        if (!p) return;
        if (!p->word.empty()) { // 找到一个词
            ans.push_back(p->word);
            p->word.clear(); // 不用再找这个词
        }
        
        visited[r][c] = true;
        search(r - 1, c, board, visited, p, ans);
        search(r + 1, c, board, visited, p, ans);
        search(r, c - 1, board, visited, p, ans);
        search(r, c + 1, board, visited, p, ans);
        visited[r][c] = false;
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
    auto ans = solution.findWords(board, words);
    for (const auto &word : ans) {
        cout << word << " ";
    }
    
    return 0;
}
