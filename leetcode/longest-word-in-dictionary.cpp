//
//  longest-word-in-dictionary
//  https://leetcode.com/problems/longest-word-in-dictionary/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    struct TrieNode {
        bool isWord;
        vector<TrieNode *> child;
        TrieNode() : child(26, NULL) { }
    };

    class Trie {
        TrieNode root;
    public:
        void insert(const string &word) {
            auto p = &root;
            for (char c : word) {
                int idx = c - 'a';
                if (!p->child[idx]) p->child[idx] = new TrieNode();
                p = p->child[idx];
            }
            p->isWord = true;
        }
        
        bool searchWithoutLastChar(const string &word) {
            if (word.empty()) return false;
            auto p = &root;        
            for (int i = 0; i < word.size() - 1; i++) {
                int idx = word[i] - 'a';
                if (!p->child[idx]) return false;
                p = p->child[idx];
                if (!p->isWord) return false;
            }
            return true;
        }
    };
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end());
        string ans;
        Trie trie;
        for (auto &word : words) {
            if (trie.searchWithoutLastChar(word)) {
                trie.insert(word);
                if (word.size() > ans.size()) ans = word;
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
