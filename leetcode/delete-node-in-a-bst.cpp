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
        if (!root) return nullptr;
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
            return root;
        }
        if (key > root->val) {
            root->right = deleteNode(root->right, key);
            return root;
        }

        if (!root->right) {
            auto left = root->left;
            delete root;
            return left;
        }
        // 找到后继节点
        auto succ = root->right;
        while (succ->left) {
            succ = succ->left;
        }
        succ->left = root->left;
        auto right = root->right;
        delete root;
        return right;
    }
};

int main(int argc, const char* argv[]) {
    return 0;
}
