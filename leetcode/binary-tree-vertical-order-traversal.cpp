//
//  binary-tree-vertical-order-traversal
//  https://leetcode.com/problems/binary-tree-vertical-order-traversal/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        // 在同一列的按层排，用bfs按层遍历
        map<int, vector<int>> cols; // 按列分桶
        queue<pair<int, TreeNode *>> q; // pair: <col,node>
        if (root) q.push({0, root});

        while (!q.empty()) {
            auto top = q.front(); q.pop();
            auto col = top.first;
            auto node = top.second;
            cols[col].push_back(node->val);
            if (node->left) q.push({col-1, node->left});
            if (node->right) q.push({col+1, node->right});
        }
        
        vector<vector<int>> ans;
        for (auto &e : cols) {
            ans.push_back(e.second);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
