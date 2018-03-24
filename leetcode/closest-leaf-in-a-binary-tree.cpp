//
//  closest-leaf-in-a-binary-tree
//  https://leetcode.com/problems/closest-leaf-in-a-binary-tree/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int findClosestLeaf(TreeNode* root, int k) {
        // 题目的意思是：树中肯定有一个节点值为k，找出离这个节点最近的叶节点值
        // 路径可沿边上下前进，其实就是把这树当作无向图，用bfs找最短路径
        // 当作无向图的话，节点最多三个邻接点：lchild, rchild, parent

        // 先dfs创建无向图，同时找出k节点（用后序遍历）
        unordered_map<TreeNode *, vector<TreeNode *>> adj;
        auto kNode = dfs(root, k, adj);
        
        queue<TreeNode *> q;
        q.push(kNode);
        unordered_set<TreeNode *> visited;
        visited.insert(kNode);
        
        while (!q.empty()) {
            auto u = q.front(); q.pop();
            if (!u->left && !u->right) return u->val;

            for (auto v : adj[u]) {
                if (visited.count(v)) continue;
                q.push(v);
                visited.insert(v);
            }
        }
        return INT_MIN;
    }
    
    TreeNode *dfs(TreeNode *root, int k, unordered_map<TreeNode *, vector<TreeNode *>> &adj) {
        if (!root) return NULL;
        auto left = dfs(root->left, k, adj);
        auto right = dfs(root->right, k, adj);
        if (root->left) {
            adj[root].push_back(root->left);
            adj[root->left].push_back(root);
        }
        if (root->right) {
            adj[root].push_back(root->right);
            adj[root->right].push_back(root);
        }
        if (left) return left;
        if (right) return right;
        if (root->val == k) return root;
        return NULL;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}