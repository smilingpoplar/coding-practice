//
//  implement-trie-prefix-tree.cpp
//  https://leetcode.com/problems/implement-trie-prefix-tree/
//
//  Created by smilingpoplar on 15/5/21.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() : child(26, NULL), isWord(false) {}
    vector<TrieNode *> child;
    bool isWord;
};

class Trie {
    TrieNode *root;
public:
    Trie() : root(new TrieNode()) { }
    ~Trie() { deleteNode(root); }
    
    // Inserts a word into the trie.
    void insert(string s) {
        auto node = root;
        for (char c : s) {
            int idx = c - 'a';
            if (!node->child[idx]) node->child[idx] = new TrieNode();
            node = node->child[idx];
        }
        node->isWord = true;
    }
    
    // Returns if the word is in the trie.
    bool search(string key) {
        auto node = root;
        for (char c : key) {
            int idx = c - 'a';
            if (!node->child[idx]) return false;
            node = node->child[idx];
        }
        return node->isWord;
    }
    
    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        auto node = root;
        for (char c : prefix) {
            int idx = c - 'a';
            if (!node->child[idx]) return false;
            node = node->child[idx];
        }
        return true;
    }
    
private:
    void deleteNode(TrieNode *node) {
        if (!node) return;
        for (auto child : node->child) {
            deleteNode(child);
        }
        delete node;
    }
};

int main(int argc, const char * argv[]) {
    Trie trie;
    trie.insert("abc");
    cout << trie.search("abc") << endl;
    cout << trie.search("ab") << endl;
    trie.insert("ab");
    cout << trie.search("ab") << endl;
    trie.insert("ab");
    cout << trie.search("ab") << endl;
    
    return 0;
}
