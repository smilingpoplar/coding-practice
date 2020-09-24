//
//  accounts-merge
//  https://leetcode.com/problems/accounts-merge/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        // 直接用mail作并查集的键，同用户的mail在同一集合
        unordered_map<string, string> parent;
        unordered_map<string, string> owner;
        for (auto &account : accounts) {
            for (int i = 1; i < account.size(); i++) {
                auto &mail = account[i];
                parent[mail] = mail; // init
                owner[mail] = account[0];
            }
        }
        for (auto &account : accounts) {
            auto px = find(account[1], parent);
            for (int i = 2; i < account.size(); i++) {
                auto py = find(account[i], parent);
                if (px != py) parent[py] = px; // unite
            }
        }
        
        // 同一集合的mail放入数组
        unordered_map<string, vector<string>> mp;
        for (auto &e : parent) {
            auto &x = e.first;
            auto px = find(e.second, parent);
            mp[px].push_back(x);
        }
        vector<vector<string>> ans;
        for (auto &e : mp) {
            auto &mails = e.second;
            sort(mails.begin(), mails.end());
            mails.insert(mails.begin(), owner[e.first]);
            ans.push_back(mails);
        }
        return ans;
    }
    
    string find(const string &mail, unordered_map<string, string> &parent) {
        if (parent[mail] != mail)
            parent[mail] = find(parent[mail], parent);
        return parent[mail];
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
