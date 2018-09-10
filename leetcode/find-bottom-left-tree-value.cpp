//
//  find-bottom-left-tree-value
//  https://leetcode.com/problems/find-bottom-left-tree-value/
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
    int findBottomLeftValue(TreeNode* root) {
        int maxLevel = INT_MIN, ans = INT_MIN;
        dfs(root, 0, maxLevel, ans);
        return ans;
    }
    
    void dfs(TreeNode *root, int level, int &maxLevel, int &ans) {
        if (!root) return;
        if (level > maxLevel) {
            maxLevel = level;
            ans = root->val;
        }
        dfs(root->left, level + 1, maxLevel, ans);
        dfs(root->right, level + 1, maxLevel, ans);
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
