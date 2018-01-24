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
        set<int> s;
        return dfs(root, k, s);
    }
    
    bool dfs(TreeNode* root, int k, set<int> &s) {
        if (!root) return false;
        if (s.find(k - root->val) != s.end()) return true;
        s.insert(root->val);
        return dfs(root->left, k, s) || dfs(root->right, k, s);
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
