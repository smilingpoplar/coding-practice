//
//  boundary-of-binary-tree
//  https://leetcode.com/problems/boundary-of-binary-tree/
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
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        // 这题的意思是：输出先序遍历过程中的左边界、叶节点、右边界
        // 为防止重复，输出：根节点、左子树中非叶节点的左边界和叶节点、右子树中叶节点和非叶节点的右边界
        if (!root) return {};
        vector<int> ans;
        ans.push_back(root->val);
        traverse(root->left, true, false, ans);
        traverse(root->right, false, true, ans);
        return ans;
    }
    
    void traverse(TreeNode *root, bool isLeftBoundary, bool isRightBoundary, vector<int> &ans) {
        if (!root) return;
        if (!root->left && !root->right) {
            ans.push_back(root->val);
            return;
        }
        if (isLeftBoundary) ans.push_back(root->val); // 先序
        // 1. root是左边界且左子树存在，则root->left是左边界；
        // 2. root是左边界但左子树不存在，则root->right是左边界；
        // 3. root是右边界且右子树存在，则root->right是右边界；
        // 4. root是右边界但右子树不存在，则root->left是右边界。
        traverse(root->left, isLeftBoundary && root->left, isRightBoundary && !root->right, ans);  // root->left相关：1、4
        traverse(root->right, isLeftBoundary && !root->left, isRightBoundary && root->right, ans); // root->right相关：2、3
        if (isRightBoundary) ans.push_back(root->val); // 后序
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
