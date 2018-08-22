//
//  inorder-successor-in-bst
//  https://leetcode.com/problems/inorder-successor-in-bst/
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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (!root || !p) return NULL;
        // bst的中序遍历是个有序数组，这题相当于要找第一个>p.val的节点
        // 类似二分搜索，root相当于二分搜索中的mid
        TreeNode *succ = NULL;
        while (root) {
            if (root->val <= p->val) { // root值太小，排除root和左子树
                root = root->right;
            } else { // root可以候选，排除右子树
                succ = root;
                root = root->left;
            }
        }
        return succ;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
