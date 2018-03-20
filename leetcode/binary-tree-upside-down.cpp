//
//  binary-tree-upside-down
//  https://leetcode.com/problems/binary-tree-upside-down/
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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        // 这个变换相当于把头左转90度看这棵树，左下角节点变成新的根
        // 递归，假设本函数能处理好左子树，只需关注当前节点和左右节点的关系变换
        if (!root || !root->left) return root;
        auto newRoot = upsideDownBinaryTree(root->left);
        root->left->left = root->right; // left child of node2
        root->left->right = root; // right child of node2
        root->left = root->right = NULL;
        return newRoot;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
