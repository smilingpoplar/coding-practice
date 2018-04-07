//
//  sentence-similarity-ii
//  https://leetcode.com/problems/sentence-similarity-ii/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

/*
class Solution {
    class UnionFind {
        vector<int> parent;
        vector<int> rank;
    public:
        UnionFind(int sz) : parent(sz), rank(sz, 0) {
            for (int i = 0; i < sz; i++)
                parent[i] = i;
        }
        
        int find(int x) {
            if (parent[x] != x)
                parent[x] = find(parent[x]);
            return parent[x];
        }
        
        void unite(int x, int y) {
            int px = find(x), py = find(y);
            if (px == py) return;
            if (rank[px] < rank[py]) {
                parent[px] = py;
            } else if (rank[py] < rank[px]) {
                parent[py] = px;
            } else {
                parent[px] = py;
                rank[py]++;
            }
        }
    };
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        if (words1.size() != words2.size()) return false;
        // 并查集，把word映射到数字id
        UnionFind uf(pairs.size() * 2);
        unordered_map<string, int> ids;
        int cnt = 0;
        for (auto &p : pairs) {
            auto &w1 = p.first, &w2 = p.second;
            if (!ids.count(w1)) ids[w1] = cnt++;
            if (!ids.count(w2)) ids[w2] = cnt++;
            uf.unite(ids[w1], ids[w2]);
        }
        for (int i = 0; i < words1.size(); i++) {
            auto &w1 = words1[i], &w2 = words2[i];
            if (w1 == w2) continue;
            if (!ids.count(w1) || !ids.count(w2)) return false;
            if (uf.find(ids[w1]) != uf.find(ids[w2])) return false; 
        }
        return true;
    }
};
*/

class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        if (words1.size() != words2.size()) return false;
        // 并查集，直接用word作为key
        unordered_map<string, string> parent;
        for (auto &p : pairs) {
            // unite
            auto pw1 = find(p.first, parent), pw2 = find(p.second, parent);
            if (pw1 != pw2) parent[pw1] = pw2;
        }
        
        for (int i = 0; i < words1.size(); i++) {
            auto &w1 = words1[i], &w2 = words2[i];
            if (w1 != w2 && find(w1, parent) != find(w2, parent)) return false;
        }
        return true;
    }
    
    string find(string s, unordered_map<string, string> &parent) {
        if (!parent.count(s)) 
            parent[s] = s;
        
        if (parent[s] != s) 
            parent[s] = find(parent[s], parent);
        return parent[s];
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
