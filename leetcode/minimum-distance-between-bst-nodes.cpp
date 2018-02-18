//
//  minimum-distance-between-bst-nodes
//  https://leetcode.com/problems/minimum-distance-between-bst-nodes/
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
    int minDiffInBST(TreeNode* root) {
        // 先序遍历，跟前个值比较
        int prev = INT_MIN;
        int ans = INT_MAX;
        preorder(root, prev, ans);
        return ans;
    }
    
    void preorder(TreeNode *root, int &prev, int &ans) {
        if (!root) return;
        preorder(root->left, prev, ans);
        if (prev != INT_MIN) ans = min(ans, root->val - prev);
        prev = root->val;
        preorder(root->right, prev, ans);
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
