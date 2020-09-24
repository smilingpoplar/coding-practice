//
//  prefix-and-suffix-search
//  https://leetcode.com/problems/prefix-and-suffix-search/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class WordFilter {
    struct TrieNode {
        vector<int> wordIdx;
        vector<TrieNode *> child;
        TrieNode() : child(26, NULL) { }
    };

    class Trie {
        TrieNode root;
    public:
        void insert(const string &word, int index) {
            auto p = &root;
            p->wordIdx.push_back(index); // ""前缀可对应单词
            for (char c : word) {
                int idx = c - 'a';
                if (!p->child[idx]) p->child[idx] = new TrieNode();
                p = p->child[idx];
                p->wordIdx.push_back(index);
            }
        }

        vector<int> search(const string &prefix) {
            auto p = &root;        
            for (char c : prefix) {
                int idx = c - 'a';
                if (!p->child[idx]) return {};
                p = p->child[idx];
            }
            return p->wordIdx;
        }
    };
    
    Trie forward;
    Trie backward;
public:
    WordFilter(vector<string> words) {
        for (int i = 0; i < words.size(); i++) {
            forward.insert(words[i], i);
            reverse(words[i].begin(), words[i].end());
            backward.insert(words[i], i);
        }
    }
    
    /*  */
    int f(string prefix, string suffix) {
        auto wordIdx1 = forward.search(prefix);
        reverse(suffix.begin(), suffix.end());
        auto wordIdx2 = backward.search(suffix);
        // 找出这两个列表的交集中的最大值
        int i = wordIdx1.size() - 1, j = wordIdx2.size() - 1;
        while (i >= 0 && j >= 0) {
            if (wordIdx1[i] == wordIdx2[j]) return wordIdx1[i];
            else if (wordIdx1[i] > wordIdx2[j]) i--;
            else j--;
        }
        return -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter obj = new WordFilter(words);
 * int param_1 = obj.f(prefix,suffix);
 */

int main(int argc, const char * argv[]) {
    return 0;
}
