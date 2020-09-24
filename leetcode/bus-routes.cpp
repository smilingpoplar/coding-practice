//
//  bus-routes
//  https://leetcode.com/problems/bus-routes/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        // 以bus作节点、busA=>stop=>busB可换乘就认为busA和busB相邻
        // 求最少乘车次数，用bst，初始时S可达的buses入队列
        if (S == T) return 0;
        
        unordered_map<int, unordered_set<int>> busesAtStop;
        for (int i = 0; i < routes.size(); i++) {
            for (int j = 0; j < routes[i].size(); j++) {
                busesAtStop[routes[i][j]].insert(i);
            }
        }
        
        queue<int> q;
        vector<bool> visited(routes.size(), false);
        int count = 0;
        for (int bus : busesAtStop[S]) {
            q.push(bus);
            visited[bus] = true;
        }
        while (!q.empty()) {
            count++;
            for (int sz = q.size(); sz > 0; sz--) {
                int bus1 = q.front(); q.pop();
                for (int stop : routes[bus1]) {
                    if (stop == T) return count;
                    for (int bus2 : busesAtStop[stop]) {
                        if (visited[bus2]) continue;                        
                        q.push(bus2);
                        visited[bus2] = true;
                    }
                }                
            }
        }
        return -1;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
