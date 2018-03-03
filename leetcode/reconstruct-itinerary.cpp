//
//  reconstruct-itinerary
//  https://leetcode.com/problems/reconstruct-itinerary/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        // 一张机票一条边，求遍历所有边的欧拉路径
        // 已知欧拉路径存在且从JFK开始，只要用边的后序遍历求逆欧拉路径
        unordered_map<string, multiset<string>> adj;
        for (auto &ticket : tickets)
            adj[ticket.first].insert(ticket.second);
        
        vector<string> ans;
        dfs("JFK", adj, ans);
        reverse(ans.begin(), ans.end()); // 逆欧拉路径
        return ans;
    }
    
    void dfs(const string &from, unordered_map<string, multiset<string>> &adj, vector<string> &ans) {
        auto &tos = adj[from];
        while (!tos.empty()) {
            auto next = *tos.begin();
            tos.erase(tos.begin()); // 相当于把边(from,to)放进visited[]数组
            dfs(next, adj, ans);
        }
        ans.push_back(from); // 后序遍历
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
