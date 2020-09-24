//
//  binary-tree-upside-down
//  https://leetcode.com/problems/binary-tree-upside-down/
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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        // 已知右节点为叶节点、左节点非空，或右节点为空。
        // 此题要将二叉树右转90度：左节点=>父节点、右节点=>左节点、父节点=>右节点。
        // 假设本函数能处理好左子树，只需考虑父节点、左节点、右节点这三者的关系。
        if (!root || !root->left) return root;
        auto newRoot = upsideDownBinaryTree(root->left);
        // 右转90度
        root->left->left = root->right;
        root->left->right = root;
        // 右节点已知为叶节点
        root->left = root->right = NULL;
        return newRoot;
    }
};

/*
class Solution {
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        // 已知右节点为叶节点、左节点非空，或右节点为空。
        // 此题要将二叉树右转90度：左节点变父节点、右节点变左节点、父节点变右节点。
        // 考虑父节点、左节点、右节点这三者的关系：
        // curr在赋值左边时为左节点视角、在赋值右边时为父节点视角
        TreeNode *curr = root, *parent = NULL, *sibling = NULL;
        while (curr) {
            auto left = curr->left;

            curr->left = sibling;
            sibling = curr->right;
            curr->right = parent;
            parent = curr;
            
            curr = left;
        }
        return parent;
    }
};
*/

int main(int argc, const char * argv[]) {
    return 0;
}
