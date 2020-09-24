//
//  implement-trie-prefix-tree
//  https://leetcode.com/problems/implement-trie-prefix-tree/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Trie {
    struct TrieNode {
        vector<TrieNode *> child;
        bool isWord;
        TrieNode() : child(26, NULL), isWord(false) { }
    };
    
    TrieNode root;
public:
    /** Initialize your data structure here. */
    Trie() {
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        auto p = &root;
        for (char c : word) {
            int idx = c - 'a';
            if (!p->child[idx]) p->child[idx] = new TrieNode();
            p = p->child[idx];
        }
        p->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto p = &root;
        for (char c : word) {
            int idx = c - 'a';
            if (!p->child[idx]) return false;
            p = p->child[idx];
        }
        return p->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        auto p = &root;
        for (char c : prefix) {
            int idx = c - 'a';
            if (!p->child[idx]) return false;
            p = p->child[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */

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
