//
//  find-duplicate-subtrees
//  https://leetcode.com/problems/find-duplicate-subtrees/
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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> count;
        vector<TreeNode *> ans;        
        dfs(root, count, ans);
        return ans;
    }
    
    string dfs(TreeNode *root, unordered_map<string, int> &count, vector<TreeNode *> &ans) {
        if (!root) return "#";
        auto left = dfs(root->left, count, ans);
        auto right = dfs(root->right, count, ans);
        auto s = to_string(root->val) + left + right;
        count[s]++;
        if (count[s] == 2) {
            ans.push_back(root);
        }
        return s;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
