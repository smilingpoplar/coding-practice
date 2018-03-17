//
//  add-and-search-word-data-structure-design
//  https://leetcode.com/problems/add-and-search-word-data-structure-design/
//
//  Created by smilingpoplar on 15/6/22.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class WordDictionary {
    struct TrieNode {
        vector<TrieNode *> child;
        bool isWord;
        TrieNode() : child(26, NULL), isWord(false) { }
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
        return rSearch(&root, word);
    }
    
    bool rSearch(TrieNode *node, string word) {
        if (!node) return false;
        auto p = node;
        for (int i = 0; i < word.size(); i++) {
            char c = word[i];
            if (c == '.') {
                string substr = word.substr(i + 1);
                for (auto child : p->child) {
                    if (rSearch(child, substr)) return true;
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
