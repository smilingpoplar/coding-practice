//
//  two-sum-iv-input-is-a-bst
//  https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
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
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> st;
        return dfs(root, k, st);
    }
    
    bool dfs(TreeNode* root, int k, unordered_set<int> &st) {
        if (!root) return false;
        if (st.count(k - root->val)) return true;
        st.insert(root->val);
        return dfs(root->left, k, st) || dfs(root->right, k, st);
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
