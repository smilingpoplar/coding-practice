//
//  evaluate-division
//  https://leetcode.com/problems/evaluate-division/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        unordered_map<string, unordered_map<string, double>> adj;
        for (int i = 0; i < equations.size(); i++) {
            auto &from = equations[i].first, &to = equations[i].second;
            adj[from][to] = values[i];
            adj[to][from] = 1 / values[i];
        }
        
        vector<double> ans;
        for (auto &query : queries) {
            auto &from = query.first, &to = query.second;
            if (!adj.count(from) || !adj.count(to)) {
                ans.push_back(-1);
            } else {
                unordered_set<string> visited;
                int oldSize = ans.size();
                dfs(from, to, adj, visited, 1, ans);
                if (ans.size() == oldSize) ans.push_back(-1);
            }
        }
        return ans;
    }
    
    // 回溯法
    void dfs(const string &src, const string &dst,
             unordered_map<string, unordered_map<string, double>> &adj, unordered_set<string> &visited,
             double prod, vector<double> &ans) {
        if (src == dst) {
            ans.push_back(prod);
            return;
        }
        if (visited.count(src)) return;
        visited.insert(src);
        
        for (auto &e : adj[src]) {
            auto &next = e.first;
            auto &cost = e.second;
            dfs(next, dst, adj, visited, prod * cost, ans);
        }
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
