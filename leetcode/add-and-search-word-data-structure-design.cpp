//
//  add-and-search-word-data-structure-design
//  https://leetcode.com/problems/add-and-search-word-data-structure-design/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class WordDictionary {
    struct TrieNode {
        vector<TrieNode *> child;
        bool isWord = false;
        TrieNode() : child(26, NULL) { }
    };
    TrieNode root;
public:
    /** Initialize your data structure here. */
    WordDictionary() {  
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        auto p = &root;
        for (char c : word) {
            int idx = c - 'a' ;
            if (!p->child[idx]) p->child[idx] = new TrieNode();
            p = p->child[idx];
        }
        p->isWord = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return rSearch(&root, word, 0);
    }
    
    bool rSearch(TrieNode *node, const string &word, int idx) {
        if (!node) return false;
        auto p = node;
        for (int i = idx; i < word.size(); i++) {
            char c = word[i];
            if (c == '.') {
                for (auto child : p->child) {
                    if (rSearch(child, word, i + 1)) return true;
                }
                return false;
            }
            int idx = c - 'a';
            if (!p->child[idx]) return false;
            p = p->child[idx];
        }
        return p->isWord;
    }
};

int main(int argc, const char * argv[]) {
    WordDictionary dict;
    dict.addWord("bad");
    dict.addWord("dad");
    dict.addWord("mad");
    cout << dict.search("pad") << endl; // 0
    cout << dict.search("bad") << endl; // 1
    cout << dict.search(".ad") << endl; // 1
    cout << dict.search("b..") << endl; // 1
    
    return 0;
}
