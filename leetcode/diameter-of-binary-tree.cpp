//
//  diameter-of-binary-tree
//  https://leetcode.com/problems/diameter-of-binary-tree/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
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
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        getHeight(root, ans);
        return ans;
    }
    
    int getHeight(TreeNode *root, int &ans) {
        if (!root) return 0;
        int left = getHeight(root->left, ans);
        int right = getHeight(root->right, ans);
        int arrow = 1 + max(left, right);
        // left高度 <=> left节点数 <=> 从root往左向下的边数
        ans = max(ans, left + right);
        return arrow;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
