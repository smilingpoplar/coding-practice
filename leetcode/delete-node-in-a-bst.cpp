//
//  delete-node-in-a-bst
//  https://leetcode.com/problems/delete-node-in-a-bst/
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return NULL;
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            if (!root->right) {
                auto left = root->left;
                delete root;
                return left;
            }
            // 把后继节点的值赋给根，并删除该后继节点
            auto curr = root->right;
            while (curr->left) curr = curr->left;
            root->val = curr->val;
            root->right = deleteNode(root->right, curr->val);
        }
        return root;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
