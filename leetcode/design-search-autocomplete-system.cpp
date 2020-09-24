//
//  design-search-autocomplete-system
//  https://leetcode.com/problems/design-search-autocomplete-system/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class AutocompleteSystem {
    struct TrieNode {
        int times = 0;
        vector<TrieNode *> child;
        TrieNode() : child(27, NULL) { }
    };

    class Trie {
        string alphabet = "abcdefghijklmnopqrstuvwxyz ";
        TrieNode root;

        int index(char c) {
            if (c == ' ') return 26;
            return c - 'a';
        }

        struct Pair {
            string sentence;
            int times;
            // 满足题目条件的要留在优先队列中。priority_queue比较函数排的是逆序，满足题目条件正好留在队中。
            bool operator<(const Pair &rhs) const {
                if (times == rhs.times) return sentence < rhs.sentence;
                return times > rhs.times;
            }
        };

        void dfs(TrieNode *p, string prefix, priority_queue<Pair> &pq) {
            if (p->times > 0) { // prefix是句子
                pq.push({ prefix, p->times });
                if (pq.size() > 3) pq.pop(); // only top 3
            }
            for (char c : alphabet) {
                int idx = index(c);
                if (!p->child[idx]) continue;
                dfs(p->child[idx], prefix + c, pq);
            }
        }

    public:
        void insert(const string &sentence, int times) {
            auto p = &root;
            for (char c : sentence) {
                int idx = index(c);
                if (!p->child[idx]) p->child[idx] = new TrieNode();
                p = p->child[idx];
            }
            p->times += times;
        }

        vector<string> search(const string &prefix) {
            auto p = &root;
            for (char c : prefix) {
                int idx = index(c);
                if (!p->child[idx]) return {};
                p = p->child[idx];
            }

            priority_queue<Pair> pq;
            dfs(p, prefix, pq);
            vector<string> ans;
            while (!pq.empty()) {
                ans.push_back(pq.top().sentence);
                pq.pop();
            }
            reverse(ans.begin(), ans.end()); // pq排的是逆序
            return ans;
        }
    };

    Trie trie;
    string typing;
public:
    AutocompleteSystem(vector<string> sentences, vector<int> times) {
        for (int i = 0; i < sentences.size(); i++) {
            trie.insert(sentences[i], times[i]);
        }
    }
    
    vector<string> input(char c) {
        if (c == '#') {
            trie.insert(typing, 1);
            typing.clear();
            return {};
        } 
        typing += c;
        return trie.search(typing);
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj.input(c);
 */

int main(int argc, const char * argv[]) {
    return 0;
}
