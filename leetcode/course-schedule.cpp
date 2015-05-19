//
//  course-schedule
//  https://leetcode.com/problems/course-schedule/
//
//  Created by smilingpoplar on 15/5/10.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    // 若能finish则图是无环有向图，即dfs时不存在回边，见图算法3.2章（回边：访问有较大后序编号的节点）
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        // 构造图
        vector<unordered_set<int>> graph(numCourses);
        for (const auto &edge : prerequisites) {
            graph[edge.second].insert(edge.first);
        }
        // 遍历图
        vector<bool> visited(numCourses, false);
        vector<int> post(numCourses, -1);
        int order = 0;
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (hasCycle(i, graph, visited, post, order)) return false;
            }
        }
        return true;
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

int main(int argc, const char * argv[]) {
    Solution solution;
    vector<pair<int, int>> prerequisites{{1,0}, {0,1}};
    cout << solution.canFinish(2, prerequisites);
    
    return 0;
}
