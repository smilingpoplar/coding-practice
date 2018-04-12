//
//  find-eventual-safe-states
//  https://leetcode.com/problems/find-eventual-safe-states/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // "安全点"是那些出度为0的点。在反转图中，不断删除入度为0的点，这些点都是安全点。
        // 这题其实就是拓扑排序
        const int N = graph.size();
        vector<vector<int>> rgraph(N);
        vector<int> indegree(N, 0);
        for (int i = 0; i < N; i++) {
            for (int j : graph[i]) {
                rgraph[j].push_back(i);
                indegree[i]++;
            }
        }
        vector<bool> isSafe(N, false);
        queue<int> q;
        for (int i = 0; i < N; i++) {
            if (indegree[i] == 0) {
                q.push(i);
                isSafe[i] = true;
            }
        }
        while (!q.empty()) {
            int node = q.front(); q.pop();
            for (int neighbor : rgraph[node]) {
                if (--indegree[neighbor] == 0) {
                    q.push(neighbor);
                    isSafe[neighbor] = true;
                }
            }
        }
        vector<int> ans;
        for (int i = 0; i < N; i++) {
            if (isSafe[i]) ans.push_back(i);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
