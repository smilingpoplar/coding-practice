//
//  longest-univalue-path
//  https://leetcode.com/problems/longest-univalue-path/
//
//  Created by smilingpoplar on 17/10/12.
//  Copyright (c) 2017年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }

    int dfs(TreeNode *root, int &ans) {
        if (!root) return 0;
        int left = dfs(root->left, ans);
        int right = dfs(root->right, ans);

        int leftEdge = 0, rightEdge = 0;
        if (root->left && root->left->val == root->val) leftEdge = 1 + left;
        if (root->right && root->right->val == root->val) rightEdge = 1 + right;
        ans = max(ans, leftEdge + rightEdge); // 经过当前节点的最大边数

        return max(leftEdge, rightEdge);
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
