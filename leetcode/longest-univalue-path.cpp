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
        arrowLen(root, ans);
        return ans;
    }

    // 返回从root往下的最大边数
    int arrowLen(TreeNode *root, int &ans) {
        if (!root) return 0;
        int left = arrowLen(root->left, ans);
        int right = arrowLen(root->right, ans);

        int arrowLeft = 0, arrowRight = 0;
        if (root->left && root->left->val == root->val) arrowLeft = 1 + left;
        if (root->right && root->right->val == root->val) arrowRight = 1 + right;
        // 经过root的最大边数
        ans = max(ans, arrowLeft + arrowRight);

        return max(arrowLeft, arrowRight);
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
