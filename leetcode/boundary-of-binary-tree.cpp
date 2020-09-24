//
//  boundary-of-binary-tree
//  https://leetcode.com/problems/boundary-of-binary-tree/
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
    vector<int> boundaryOfBinaryTree(TreeNode *root) {
        // 输出根节点、左子树的非叶左边界、叶节点、右子树的非叶右边界
        if (!root) return {};
        vector<int> ans;
        ans.push_back(root->val);
        leftBoundary(root->left, ans);
        leaves(root, ans);
        rightBoundary(root->right, ans);
        return ans;
    }
    
    void leftBoundary(TreeNode *root, vector<int> &ans) {
        if (!root || (!root->left && !root->right)) return;
        ans.push_back(root->val);
        if (root->left) leftBoundary(root->left, ans);
        else leftBoundary(root->right, ans);
    }
    
    void leaves(TreeNode *root, vector<int> &ans) {
        if (!root) return;
        if (!root->left && !root->right) {
            ans.push_back(root->val);
        } else {
           leaves(root->left, ans);
           leaves(root->right, ans);
        }        
    }
    
    void rightBoundary(TreeNode *root, vector<int> &ans) {
        if (!root || (!root->left && !root->right)) return;
        if (root->right) rightBoundary(root->right, ans);
        else rightBoundary(root->left, ans);
        ans.push_back(root->val);
    }
};

/*
class Solution {
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        // 输出根节点、左子树中非叶左边界和叶节点、右子树中叶节点和非叶右边界
        if (!root) return {};
        vector<int> ans;
        ans.push_back(root->val);
        traverse(root->left, true, false, ans);
        traverse(root->right, false, true, ans);
        return ans;
    }
    
    void traverse(TreeNode *root, bool leftbd, bool rightbd, vector<int> &ans) {
        if (!root) return;
        if (!root->left && !root->right) {
            ans.push_back(root->val);
            return;
        }

        if (leftbd) ans.push_back(root->val); // 先序
        // 1. root是左边界、左子树存在   => root->left是左边界
        // 2.       左边界、左子树不存在 => root->right是左边界
        // 3.       右边界、右子树存在   => root->right是右边界
        // 4.       右边界、右子树不存在 => root->left是右边界
        // root->left相关：1、4，root->right相关：2、3
        traverse(root->left, leftbd && root->left, rightbd && !root->right, ans);
        traverse(root->right, leftbd && !root->left, rightbd && root->right, ans);
        if (rightbd) ans.push_back(root->val); // 后序
    }
};
*/

int main(int argc, const char * argv[]) {
    return 0;
}
