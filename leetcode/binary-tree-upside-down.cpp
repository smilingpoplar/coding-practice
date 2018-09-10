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
        // 已知右节点为叶节点、此时左节点非空，或右节点为空。
        // 此题要将二叉树右转90度：左节点变根节点、右节点变左节点、根节点变右节点。
        // 递归，假设本函数能处理好左子树，只需考虑当前节点、左节点、右节点这三者的关系。
        if (!root || !root->left) return root;
        auto newRoot = upsideDownBinaryTree(root->left);
        // root->left变成root->right、root的父节点
        root->left->left = root->right;
        root->left->right = root;
        // 切断root的左右节点链接
        root->left = root->right = NULL;
        return newRoot;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
