//
//  increasing-order-search-tree
//  https://leetcode.com/problems/increasing-order-search-tree/
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
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode dummy(0);
        auto prev = &dummy;
        inorder(root, prev);
        return dummy.right;
    }
    
    void inorder(TreeNode *root, TreeNode* &prev) {
        if (!root) return;
        inorder(root->left, prev);
        prev->right = root;
        root->left = NULL;
        prev = root;
        inorder(root->right, prev);
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
