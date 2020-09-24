//
//  map-sum-pairs
//  https://leetcode.com/problems/map-sum-pairs/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

struct TrieNode {
    vector<TrieNode *> child;
    int sum = 0;
    TrieNode() : child(26, NULL) {}
};

class MapSum {
    unordered_map<string, int> mp; // 用来放insert数据
    TrieNode root;
public:
    /** Initialize your data structure here. */
    MapSum() {
    }
    
    void insert(string key, int val) {
        int delta = val - mp[key];
        mp[key] = val;
        auto p = &root;
        for (char c : key) {
            int idx = c - 'a';
            if (!p->child[idx]) p->child[idx] = new TrieNode();
            p = p->child[idx];
            p->sum += delta;
        }
    }
    
    int sum(string prefix) {
        auto p = &root;
        for (char c : prefix) {
            p = p->child[c - 'a'];
            if (!p) return 0;
        }
        return p->sum;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */

int main(int argc, const char * argv[]) {    
    return 0;
}
