//
//  find-largest-value-in-each-tree-row
//  https://leetcode.com/problems/find-largest-value-in-each-tree-row/
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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        dfs(root, 0, ans);
        return ans;
    }
    
    void dfs(TreeNode *root, int level, vector<int> &ans) {
        if (!root) return;
        if (level == ans.size()) ans.push_back(root->val);
        else ans[level] = max(ans[level], root->val);
        dfs(root->left, level + 1, ans);
        dfs(root->right, level + 1, ans);
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
