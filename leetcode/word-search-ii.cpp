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

class Solution {
    class TrieNode {
    public:
        vector<TrieNode *> child;
        string word;
        TrieNode() : child(26, NULL) {}
    };

    TrieNode root;
public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
        if (board.empty()) return {};
        const int M = board.size();
        const int N = board[0].size();
        vector<vector<bool>> visited(M, vector<bool>(N, false));
        for (auto &word : words) {
            insert(word);
        }

        vector<string> ans;
        for (int r = 0; r < M; r++) {
            for (int c = 0; c < N; c++) {
                dfs(r, c, board, visited, &root, ans);
            }
        }
        return ans;
    }

    void insert(const string &word) {
        auto p = &root;
        for (char c : word) {
            int idx = c - 'a';
            if (!p->child[idx]) p->child[idx] = new TrieNode();
            p = p->child[idx];
        }
        p->word = word;
    }

    void dfs(int r, int c, const vector<vector<char>> &board, 
             vector<vector<bool>> &visited, TrieNode *node, vector<string> &ans) {
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size()) return;
        if (visited[r][c]) return;
        // 回溯法，在trie中搜索board[r][c]
        auto p = node->child[board[r][c] - 'a'];
        visited[r][c] = true;
        if (p) {
            if (!p->word.empty()) {
                ans.push_back(p->word);
                p->word.clear(); // 不再搜索这个词
            }
            dfs(r - 1, c, board, visited, p, ans);
            dfs(r + 1, c, board, visited, p, ans);
            dfs(r, c - 1, board, visited, p, ans);
            dfs(r, c + 1, board, visited, p, ans);
        }
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
