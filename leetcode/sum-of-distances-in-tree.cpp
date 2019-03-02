//
//  sum-of-distances-in-tree
//  https://leetcode.com/problems/sum-of-distances-in-tree/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        // 设subtreeDist(x)表示x到所有x子树节点的距离之和，nodeCount(x)表示子树x的节点数，
        // dist(x)表示x到所有其他节点的距离之和。考虑父节点p和子节点c，
        // 1. 已知subtreeDist(NULL)==0，后序遍历求subtreeDist(p)
        // subtreeDist(p) = sum( subtreeDist(c[i])+nodeCount(c[i]) )
        // 最终 subtreeDist(root) == dist(root)
        // 2. 已知dist(p)，先序遍历求dist(c)。设树中除子树c外的含p的其他部分为o，
        // 从dist(p)（所有其他节点到p）变为dist(c)（所有其他节点到c），o中的节点距离+1，c中的节点距离-1，
        // 所以 dist(c) = dist(p)+nodeCount(o)-nodeCount(c) = dist(p)+N-2*nodeCount(c)
        vector<unordered_set<int>> adj(N);
        for (auto &e : edges) {
            adj[e[0]].insert(e[1]);
            adj[e[1]].insert(e[0]);
        }
        vector<bool> visited1(N, false), visited2(N, false);

        vector<int> ans(N, 0), nodeCount(N, 0);
        postOrder(0, adj, visited1, nodeCount, ans);
        preOrder(0, adj, visited2, nodeCount, N, ans);
        return ans;
    }

    void postOrder(int root, vector<unordered_set<int>>& adj, vector<bool> &visited,
                  vector<int> &nodeCount, vector<int> &subtreeDist) {
        visited[root] = true;

        for (int child : adj[root]) {
            if (visited[child]) continue;
            postOrder(child, adj, visited, nodeCount, subtreeDist);
            nodeCount[root] += nodeCount[child];
            subtreeDist[root] += subtreeDist[child] + nodeCount[child];
        }
        nodeCount[root] += 1;        
    }
    
    void preOrder(int root, vector<unordered_set<int>>& adj, vector<bool> &visited, 
                  vector<int> &nodeCount, int N, vector<int> &dist) {
        visited[root] = true;

        for (int child : adj[root]) {
            if (visited[child]) continue;
            dist[child] = dist[root] + N - 2 * nodeCount[child];
            preOrder(child, adj, visited, nodeCount, N, dist);
        }
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
