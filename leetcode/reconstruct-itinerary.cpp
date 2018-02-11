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
        // dfs的后序编号=>逆拓扑排序
        // 但这里允许有环，要在访问邻接点前把邻接点从当前点的邻接列表中拿掉
        unordered_map<string, multiset<string>> adj; // 用multiset是因为可有相同目的地的多张机票
        for (auto &ticket : tickets)
            adj[ticket.first].insert(ticket.second);
        
        vector<string> ans;
        dfs("JFK", adj, ans);
        reverse(ans.begin(), ans.end()); // 逆拓扑排序=>拓扑排序
        return ans;
    }
    
    void dfs(const string &from, unordered_map<string, multiset<string>> &adj, vector<string> &ans) {
        auto &tos = adj[from];
        while (!tos.empty()) {
            auto next = *tos.begin();
            tos.erase(tos.begin()); // 要在访问邻接点前把邻接点从当前点的邻接列表中拿掉
            dfs(next, adj, ans);
        }
        ans.push_back(from); // dfs的后序编号
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
