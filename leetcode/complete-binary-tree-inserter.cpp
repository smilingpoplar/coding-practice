//
//  complete-binary-tree-inserter
//  https://leetcode.com/problems/complete-binary-tree-inserter/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

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
class CBTInserter {
    vector<TreeNode *> data;
public:
    CBTInserter(TreeNode* root) {
        // 把二叉树按层展开
        data.push_back(root);
        for (int i = 0; i < data.size(); i++) {
            if (data[i]->left) data.push_back(data[i]->left);
            if (data[i]->right) data.push_back(data[i]->right);
        }
    }
    
    int insert(int v) {
        auto node = new TreeNode(v);
        data.push_back(node);
        // 节点i（0-based）的父节点是(i-1)/2
        int i = (int)data.size() - 1, p = (i-1)/2;
        if (i % 2 == 1) data[p]->left = node;
        else data[p]->right = node;
        return data[p]->val;
    }
    
    TreeNode* get_root() {
        return data[0];
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */

int main(int argc, const char * argv[]) {    
    return 0;
}
