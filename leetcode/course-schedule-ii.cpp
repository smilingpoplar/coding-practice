//
//  course-schedule-ii
//  https://leetcode.com/problems/course-schedule-ii/
//
//  Created by smilingpoplar on 15/5/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

/*
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        // 求拓扑排序，即求逆图上的逆拓扑排序，而逆拓扑排序又由后序编号生成，所以先求逆图上的后序编号
        // 生成逆图
        vector<unordered_set<int>> graph(numCourses);
        for (const auto &edge : prerequisites) {
            graph[edge.first].insert(edge.second);
        }
        // 遍历图，dfs时若存在回边则有环（回边：访问后序编号较大的节点）
        vector<bool> visited(numCourses, false);
        vector<int> post(numCourses, -1);
        int order = 0;
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (hasCycle(i, graph, visited, post, order)) {
                    return {};
                }
            }
        }
        // 由后序编号生成逆拓扑排序
        vector<int> topoI(numCourses);
        for (int i = 0; i < numCourses; i++) {
            topoI[post[i]] = i;  // 课程i在第post[i]个学
        }
        return topoI;
    }
private:
    bool hasCycle(int v, const vector<unordered_set<int>> &graph, vector<bool> &visited, vector<int> &post, int &order) {
        visited[v] = true;
        for (int next : graph[v]) {
            if (!visited[next]) {
                if (hasCycle(next, graph, visited, post, order)) return true;
            } else if (post[next] == -1) {
                return true; // 回边
            }
        }
        post[v] = order++;
        return false;
    }
};
*/

#include <queue>

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        // 通过bfs不断删除源点（入度为0的点）来拓扑排序，若完不成所有点的拓扑排序则有环
        // 生成图
        vector<unordered_set<int>> graph(numCourses);
        for (const auto &edge : prerequisites) {
            graph[edge.second].insert(edge.first);
        }
        // 计算入度
        vector<int> indegree(numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            for (int to : graph[i]) {
                ++indegree[to];
            }
        }
        // 源点队列
        queue<int> source;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) source.push(i);
        }
        // 不断删除源点
        vector<int> topo;
        while (!source.empty()) {
            int v = source.front();
            source.pop();
            topo.push_back(v);
            for (int to : graph[v]) {
                --indegree[to];
                if (indegree[to] == 0) source.push(to);
            }
        }
        if (topo.size() != numCourses) return {};
        return topo;
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
