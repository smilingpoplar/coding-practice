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
        arrowLength(root, ans);
        return ans;
    }
    
    int arrowLength(TreeNode *root, int &ans) {
        // 从root往下的最大边数
        if (!root) return 0;
        int left = arrowLength(root->left, ans);
        int right = arrowLength(root->right, ans);

        // 后序遍历，更新ans
        int arrowLeft = 0, arrowRight = 0;
        if (root->left && root->left->val == root->val) arrowLeft = 1 + left;
        if (root->right && root->right->val == root->val) arrowRight = 1 + right;
        ans = max(ans, arrowLeft + arrowRight);

        return max(arrowLeft, arrowRight);
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
