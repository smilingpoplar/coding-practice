//
//  maximum-difference-between-node-and-ancestor
//  https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/
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
    int maxAncestorDiff(TreeNode* root) {
        int ans = 0;
        dfs(root, INT_MAX, INT_MIN, ans);
        return ans;
    }
    
    void dfs(TreeNode *root, int mn, int mx, int &ans) {
        if (!root) return;
        mn = min(mn, root->val);
        mx = max(mx, root->val);
        dfs(root->left, mn, mx, ans);
        dfs(root->right, mn, mx, ans);
        ans = max(ans, mx - mn);
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
