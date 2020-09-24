//
//  sum-of-left-leaves
//  https://leetcode.com/problems/sum-of-left-leaves/
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
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
        int ans = 0;
        if (root->left) {
            if (!root->left->left && !root->left->right) ans += root->left->val;
            else ans += sumOfLeftLeaves(root->left);
        }
        ans += sumOfLeftLeaves(root->right);
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
