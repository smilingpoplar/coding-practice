//
//  binary-tree-pruning
//  https://leetcode.com/problems/binary-tree-pruning/
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
    TreeNode* pruneTree(TreeNode* root) {
        return containsOne(root) ? root : NULL;
    }
    
    bool containsOne(TreeNode *root) {
        if (!root) return false;
        auto left = containsOne(root->left);
        auto right = containsOne(root->right);
        if (!left) root->left = NULL;
        if (!right) root->right = NULL;
        return (root->val == 1) || left || right;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
