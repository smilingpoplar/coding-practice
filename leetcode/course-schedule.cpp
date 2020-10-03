//
//  course-schedule
//  https://leetcode.com/problems/course-schedule/
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
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // 每个节点用dfs查环，即dfs时遇到标记为VISITING的节点
        // 0: UNVISITED, 1: VISITING, 2: VISITED
        vector<unordered_set<int>> graph(numCourses);
        for (const auto &edge : prerequisites) {
            graph[edge[1]].insert(edge[0]);
        }
        vector<int> color(numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            if (hasCycle(i, color, graph)) return false;
        }
        return true;
    }

    bool hasCycle(int u, vector<int> &color, const vector<unordered_set<int>> &graph) {
        if (color[u] != 0) return color[u] == 1;
        color[u] = 1;
        for (int v : graph[u]) {
            if (hasCycle(v, color, graph)) return true;
        }
        color[u] = 2;
        return false;
    }
};
*/

#include <queue>

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // 拓扑排序：不断删除入度为0的点，其实就是bfs
        vector<unordered_set<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);
        for (auto &edge : prerequisites) {
            graph[edge[1]].insert(edge[0]);
            indegree[edge[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) q.push(i);
        }
        int count = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            count++;
            for (int to : graph[u]) {
                if (--indegree[to] == 0) q.push(to);
            }
        }
        return count == numCourses;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    vector<pair<int, int>> prerequisites{{1,0}, {0,1}};
    cout << solution.canFinish(2, prerequisites);
    
    return 0;
}
