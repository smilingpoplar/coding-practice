//
//  replace-words
//  https://leetcode.com/problems/replace-words/
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
            p->word = word;
        }

        string shortestPrefix(const string &word) {
            auto p = &root;
            for (char c : word) {
                int idx = c - 'a';
                if (!p->child[idx]) break;
                p = p->child[idx];
                if (!p->word.empty()) return p->word;
            }
            return word;
        }
    };
    
public:
    string replaceWords(vector<string>& dict, string sentence) {
        Trie trie;
        for (auto &word : dict) {
            trie.insert(word);
        }

        istringstream iss(sentence);
        ostringstream oss;
        string word;
        while (iss >> word) {
            if (oss.tellp() > 0) oss << " ";
            oss << trie.shortestPrefix(word);
        }
        return oss.str();
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
