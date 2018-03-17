//
//  accounts-merge
//  https://leetcode.com/problems/accounts-merge/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
    class DisjointSetUnion {
        vector<int> parent;
    public:
        DisjointSetUnion(int N) : parent(N) {
            for (int i = 0; i < N; i++) {
                parent[i] = i;
            }
        }
        
        int find(int x) {
            if (parent[x] != x) 
                parent[x] = find(parent[x]);
            return parent[x];
        }
        
        // union
        void merge(int x, int y) { 
            parent[find(x)] = find(y);
        }
    };
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int mailCount = 0;
        unordered_map<string, int> mailToId;
        unordered_map<int, string> idToName;
        for (auto &account : accounts) {
            for (int i = 1; i < account.size(); i++) {
                const string &mail = account[i];
                if (!mailToId.count(mail)) {
                    mailToId[mail] = mailCount++;
                }
                int id = mailToId[mail];
                idToName[id] = account[0];
            }
        }        
        
        // 并查集
        DisjointSetUnion dsu(mailCount);
        for (auto &account : accounts) {
            for (int i = 2; i < account.size(); i++) {
                dsu.merge(mailToId[account[1]], mailToId[account[i]]);
            }
        }
        // 同集合的mail合并
        unordered_map<int, vector<string>> mp;
        for (auto &e : mailToId) {
            mp[dsu.find(e.second)].push_back(e.first);
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
