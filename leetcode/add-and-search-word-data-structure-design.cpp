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
    class TrieNode {
    public:
        TrieNode() : next(26, NULL), isWord(false) { }
        vector<TrieNode *> next;
        bool isWord;
    };
public:
    WordDictionary() : _root(new TrieNode()) { }
    ~WordDictionary() { deleteNode(_root); }
    
    // Adds a word into the data structure.
    void addWord(string word) {
        auto node = _root;
        for (char c : word) {
            int index = c - 'a' ;
            if (!node->next[index]) node->next[index] = new TrieNode();
            node = node->next[index];
        }
        node->isWord = true;
    }
    
    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return search(_root, word);
    }
private:
    bool search(TrieNode *root, const string &word) {
        if (!root) return false;
        auto node = root;
        for (int i = 0; i < word.size(); ++i) {
            char c = word[i];
            if (c == '.') {
                string substr = word.substr(i + 1);
                for (auto next : node->next) {
                    if (search(next, substr)) return true;
                }
                return false;
            }
            int index = c - 'a';
            if (!node->next[index]) return false;
            node = node->next[index];
        }
        return node->isWord;
    }
    
    void deleteNode(TrieNode *node) {
        if (!node) return;
        for (auto next : node->next) {
            deleteNode(next);
        }
        delete node;
    }
    
    TrieNode *_root;
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
