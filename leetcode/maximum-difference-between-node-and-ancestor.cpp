//
//  maximum-difference-between-node-and-ancestor
//  https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/
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
    int maxAncestorDiff(TreeNode* root) {
        int ans = 0;
        dfs(root, INT_MAX, INT_MIN, ans);
        return ans;
    }
    
    void dfs(TreeNode *root, int pathMin, int pathMax, int &ans) {
        if (!root) return;
        pathMin = min(pathMin, root->val);
        pathMax = max(pathMax, root->val);
        dfs(root->left, pathMin, pathMax, ans);
        dfs(root->right, pathMin, pathMax, ans);
        ans = max(ans, pathMax - pathMin);
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
