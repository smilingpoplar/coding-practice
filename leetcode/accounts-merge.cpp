//
//  accounts-merge
//  https://leetcode.com/problems/accounts-merge/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int mailCount = 0;
        unordered_map<string, int> mailToId;
        unordered_map<int, string> idToName;
        for (auto &account : accounts) {
            for (int i = 1; i < account.size(); i++) {
                auto &mail = account[i];
                if (!mailToId.count(mail)) {
                    mailToId[mail] = mailCount++;
                }
                int id = mailToId[mail];
                idToName[id] = account[0];
            }
        }        
        
        // 并查集
        UnionFind uf(mailCount);
        for (auto &account : accounts) {
            for (int i = 2; i < account.size(); i++) {
                uf.unite(mailToId[account[1]], mailToId[account[i]]);
            }
        }
        // 同集合的mail合并
        unordered_map<int, vector<string>> mp;
        for (auto &e : mailToId) {
            mp[uf.find(e.second)].push_back(e.first);
        }
        vector<vector<string>> ans;
        for (auto &e : mp) {
            auto mails = e.second;
            sort(mails.begin(), mails.end());
            mails.insert(mails.begin(), idToName[e.first]);
            ans.push_back(mails);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
