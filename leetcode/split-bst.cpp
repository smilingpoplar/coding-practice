//
//  split-bst
//  https://leetcode.com/problems/split-bst/
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
    vector<TreeNode*> splitBST(TreeNode* root, int V) {
        if (!root) return {NULL, NULL};
        if (root->val <= V) { // root分在左边
            auto splitted = splitBST(root->right, V);
            root->right = splitted[0];
            splitted[0] = root;
            return splitted;
        } else {
            auto splitted = splitBST(root->left, V);
            root->left = splitted[1];
            splitted[1] = root;
            return splitted;
        }
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
