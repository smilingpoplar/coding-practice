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
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // 一张机票一条边，求遍历所有边的欧拉路径
        // 已知欧拉路径存在且从JFK开始，用Hierholzer算法：
        // 从图中删除邻接边再dfs递归，后序遍历输出到栈中。 
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
