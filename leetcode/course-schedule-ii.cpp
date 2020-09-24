//
//  course-schedule-ii
//  https://leetcode.com/problems/course-schedule-ii/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

/*
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        // dfs后序编号是逆拓扑排序
        vector<unordered_set<int>> graph(numCourses);
        for (auto &edge : prerequisites) {
            graph[edge.second].insert(edge.first);
        }
        // 0: UNVISITED, 1: VISITING, 2: VISITED
        vector<int> color(numCourses, 0);
        vector<int> ans;
        for (int i = 0; i < numCourses; i++) {
            if (hasCycle(i, graph, color, ans)) return {};
        }
        reverse(ans.begin(), ans.end()); // 逆拓扑排序
        return ans;
    }
private:
    bool hasCycle(int u, const vector<unordered_set<int>> &graph, 
                  vector<int> &color, vector<int> &ans) {
        if (color[u] != 0) return color[u] == 1;
        color[u] = 1;
        for (int v : graph[u]) {
            if (hasCycle(v, graph, color, ans)) return true;
        }
        color[u] = 2;
        ans.push_back(u);
        return false;
    }
};
*/

#include <queue>

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        // 拓扑排序，bfs不断删除入度为0的点，若完不成所有点的拓扑排序则有环
        vector<unordered_set<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        for (const auto &edge : prerequisites) {
            adj[edge.second].insert(edge.first);
            indegree[edge.first]++;
        }

        vector<int> ans;
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) q.push(i);
        }
        while (!q.empty()) {
            int u = q.front(); q.pop();
            ans.push_back(u);
            for (int to : adj[u]) {
                if (--indegree[to] == 0) q.push(to);
            }
        }
        if (ans.size() != numCourses) return {};
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    vector<pair<int, int>> prerequisites{{5,8},{3,5},{1,9},{4,5},{0,2},{1,9},{7,8},{4,9}};
    auto result = solution.findOrder(10, prerequisites);
    for (int course : result) {
        cout << course;
    }
    
    return 0;
}
