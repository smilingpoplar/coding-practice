//
//  map-sum-pairs
//  https://leetcode.com/problems/map-sum-pairs/
//
//  Created by smilingpoplar on 18/01/18.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

struct TrieNode {
    unordered_map<char, TrieNode *> child;
    int sum = 0;
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
        TrieNode *cur = &root;
        for (char c : key) {
            if (!cur->child[c]) cur->child[c] = new TrieNode();
            cur = cur->child[c];
            cur->sum += delta;
        }
    }
    
    int sum(string prefix) {
        TrieNode *cur = &root;
        for (char c : prefix) {
            cur = cur->child[c];
            if (!cur) return 0;
        }
        return cur->sum;
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
