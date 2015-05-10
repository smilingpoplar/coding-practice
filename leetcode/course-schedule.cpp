//
//  course-schedule
//  https://leetcode.com/problems/course-schedule/
//
//  Created by smilingpoplar on 15/5/10.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 若能finish则图是无环有向图，即dfs时不存在回边，见图算法3.2章（回边：访问有较大后序编号的节点）
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // 构造图
        vector<vector<int>> graph(numCourses, vector<int>());
        for (const auto &edge : prerequisites) {
            graph[edge[0]].push_back(edge[1]);
        }
        // 遍历图
        vector<bool> visited(numCourses, false);
        vector<int> postOrder(numCourses, -1);
        int order = 0;
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (hasCycle(i, i, graph, visited, postOrder, order)) return false;
            }
        }
        return true;
    }
private:
    bool hasCycle(int from, int to, const vector<vector<int>> &graph, vector<bool> &visited, vector<int> &postOrder, int &order) {
        visited[to] = true;
        for (int i = 0; i < graph[to].size(); i++) {
            int next = graph[to][i];
            if (!visited[next]) {
                if (hasCycle(to, next, graph, visited, postOrder, order)) return true;
            } else if (postOrder[next] == -1) {
                return true; // 回边
            }
        }
        postOrder[to] = order++;
        return false;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    vector<vector<int>> prerequisites{{1,0}, {0,1}};
    cout << solution.canFinish(2, prerequisites);
    
    return 0;
}
