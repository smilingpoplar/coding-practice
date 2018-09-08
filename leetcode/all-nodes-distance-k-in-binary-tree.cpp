//
  //  all-nodes-distance-k-in-binary-tree
  //  https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        if (!target) return {};
        // 先用dfs构造出图，把父节点当作一个邻接点
        unordered_map<TreeNode*, vector<TreeNode*>> adj;
        dfs(root, NULL, adj);
        // 再bfs求距离为K的节点
        queue<TreeNode*> q;
        q.push(target);
        unordered_set<TreeNode*> visited;
        visited.insert(target);
        while (!q.empty() && K--) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                auto top = q.front(); q.pop();
                for (auto &next : adj[top]) {
                    if (visited.count(next)) continue;
                    q.push(next);
                    visited.insert(next);
                }
            }
        }
        
        vector<int> ans;
        while (!q.empty()) {
            auto top = q.front(); q.pop();
            ans.push_back(top->val);
        }
        return ans;
    }
    
    void dfs(TreeNode *root, TreeNode *parent, 
             unordered_map<TreeNode*, vector<TreeNode*>> &adj) {
        if (!root) return;
        if (parent) adj[root].push_back(parent);
        if (root->left) adj[root].push_back(root->left);
        if (root->right) adj[root].push_back(root->right);
        
        dfs(root->left, root, adj);
        dfs(root->right, root, adj);
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
