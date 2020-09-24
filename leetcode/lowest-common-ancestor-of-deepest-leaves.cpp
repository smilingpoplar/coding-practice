//
//  lowest-common-ancestor-of-deepest-leaves
//  https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return getHeight(root).second;
    }

    // 返回：(height, lcaWithDeepest)
    pair<int, TreeNode*> getHeight(TreeNode *root) {
        if (!root) return {0, NULL};
        auto left = getHeight(root->left);
        auto right = getHeight(root->right);

        int h1 = left.first, h2 = right.first;
        if (h1 > h2) return {1 + h1, left.second};
        if (h1 < h2) return {1 + h2, right.second};
        return {1 + h1, root};
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
