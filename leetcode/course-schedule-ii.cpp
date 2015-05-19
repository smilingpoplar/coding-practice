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

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        // 求拓扑排序，因为拓扑排序等于逆图上的逆拓扑排序，又逆拓扑排序等于后序编号，所以求逆图上的后序编号
        // 生成逆图
        vector<unordered_set<int>> graph(numCourses);
        for (const auto &edge : prerequisites) {
            graph[edge.first].insert(edge.second);
        }
        // 遍历图，dfs时若存在回边（访问后序编号较大的节点）则无法拓扑排序
        vector<bool> visited(numCourses, false);
        vector<int> post(numCourses, -1);
        int order = 0;
        for (int i = 0; i < numCourses; ++i) {
            if (!visited[i]) {
                if (hasCycle(i, graph, visited, post, order)) {
                    return {};
                }
            }
        }
        // 由拓扑排序生成课程排序
        vector<int> result(numCourses);
        for (int i = 0; i < numCourses; ++i) {
            result[post[i]] = i;  // 课程i在第post[i]个学
        }
        return result;
    }
private:
    bool hasCycle(int v, const vector<unordered_set<int>> &graph, vector<bool> &visited, vector<int> &post, int &order) {
        visited[v] = true;
        for (int next : graph[v]) {
            if (!visited[next]) {
                if (hasCycle(next, graph, visited, post, order)) return true;
            } else if (post[next] == -1) {
                return true;
            }
        }
        post[v] = order++;
        return false;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    vector<pair<int, int>> prerequisites{{2,0}, {2,1}};
    auto result = solution.findOrder(3, prerequisites);
    for (int course : result) {
        cout << course;
    }
    
    return 0;
}
