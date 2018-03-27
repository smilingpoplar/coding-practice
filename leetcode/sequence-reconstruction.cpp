//
//  sequence-reconstruction
//  https://leetcode.com/problems/sequence-reconstruction/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        // 拓扑排序，bfs不断删除入度为0的点
        // 生成图
        const int N = org.size();
        unordered_map<int, unordered_set<int>> adj;
        unordered_map<int, int> indegree;
        for (auto &seq : seqs) {
            for (int num : seq) { // 检查点的合法性
                if (num <= 0 || num > N) return false;
                indegree[num] = 0; // 要区分不存在的点和入度为0的点
            }
            for (int i = 0; i + 1 < seq.size(); i++) {
                adj[seq[i]].insert(seq[i+1]);
            }
        }
        for (auto &e : adj) {
            for (int v : e.second) {
                indegree[v]++;
            }
        }

        queue<int> Q;
        for (auto &e : indegree) {
            if (e.second == 0) {
                Q.push(e.first);
            }
        }
        vector<int> ans;
        while (!Q.empty()) {
            if (Q.size() > 1) return false; // 为满足拓扑序唯一，同时只能有一个入度为0的点
            int u = Q.front(); Q.pop();
            ans.push_back(u);
            for (int v : adj[u]) {
                if (--indegree[v] == 0) Q.push(v);
            }
        }
        return ans == org;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
