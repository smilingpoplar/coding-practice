//
//  diameter-of-binary-tree
//  https://leetcode.com/problems/diameter-of-binary-tree/
//
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
        dfs(root, ans);
        return ans;
    }
    
    int dfs(TreeNode *root, int &ans) {
        if (!root) return 0;

        int left = dfs(root->left, ans);
        int right = dfs(root->right, ans);
        ans = max(ans, left + right); // 经过当前节点的直径长

        return 1 + max(left, right);
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
