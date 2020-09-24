//
//  all-paths-from-source-to-target
//  https://leetcode.com/problems/all-paths-from-source-to-target/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> path = { 0 };
        dfs(0, graph, path, ans);
        return ans;
    }
    
    void dfs(int node, vector<vector<int>>& graph, vector<int> &path, vector<vector<int>> &ans) {
        if (node == (int)graph.size() - 1) {
            ans.push_back(path);
            return;
        } 
        for (int neighbor : graph[node]) {
            path.push_back(neighbor);
            dfs(neighbor, graph, path, ans);
            path.pop_back();
        }
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
