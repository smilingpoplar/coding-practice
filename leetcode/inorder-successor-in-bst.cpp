//
//  inorder-successor-in-bst
//  https://leetcode.com/problems/inorder-successor-in-bst/
//
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
        // 类似二分搜索，root就是二分搜索中的mid
        TreeNode *succ = NULL;
        while (root) {
            if (root->val > p->val) { // root作候选，看左边有没更小的
                succ = root;
                root = root->left;
            } else { // root值太小，排除root和左子树
                root = root->right;
            }
        }
        return succ;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
