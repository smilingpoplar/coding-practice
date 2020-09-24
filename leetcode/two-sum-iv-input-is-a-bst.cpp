//
//  two-sum-iv-input-is-a-bst
//  https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
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
        unordered_set<int> seen;
        return dfs(root, k, seen);
    }
    
    bool dfs(TreeNode* root, int k, unordered_set<int> &seen) {
        if (!root) return false;
        if (seen.count(k - root->val)) return true;
        seen.insert(root->val);
        return dfs(root->left, k, seen) || dfs(root->right, k, seen);
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
