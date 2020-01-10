//
//  binary-tree-longest-consecutive-sequence
//  https://leetcode.com/problems/binary-tree-longest-consecutive-sequence/
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
    int longestConsecutive(TreeNode* root) {
        int ans = 0;
        arrowNodesCount(root, ans);
        return ans;
    }
    
    int arrowNodesCount(TreeNode *root, int &ans) {
        if (!root) return 0;
        auto left = arrowNodesCount(root->left, ans);
        auto right = arrowNodesCount(root->right, ans);

        int len = 1;
        if (root->left && root->left->val == root->val + 1)
            len = max(len, 1 + left);
        if (root->right && root->right->val == root->val + 1)
            len = max(len, 1 + right);
        ans = max(ans, len);
        return len;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
