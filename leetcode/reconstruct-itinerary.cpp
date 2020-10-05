//
//  reconstruct-itinerary
//  https://leetcode.com/problems/reconstruct-itinerary/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // 已知欧拉路径存在且从JFK开始，一张机票一条边，求遍历所有边的欧拉路径
        // Hierholzer算法：删除出边再dfs递归，无边可删时把当前点输出到栈。 
        unordered_map<string, multiset<string>> adj;
        for (auto &ticket : tickets)
            adj[ticket[0]].insert(ticket[1]);
        
        vector<string> ans;
        dfs("JFK", adj, ans);
        reverse(ans.begin(), ans.end()); // 逆欧拉路径
        return ans;
    }

    void dfs(const string &from, unordered_map<string, multiset<string>> &adj, vector<string> &ans) {
        auto &tos = adj[from];
        while (!tos.empty()) {
            auto next = *tos.begin();
            tos.erase(tos.begin());
            dfs(next, adj, ans);
        }
        ans.push_back(from); // ans当栈用
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
