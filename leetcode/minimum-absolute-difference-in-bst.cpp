//
//  minimum-absolute-difference-in-bst
//  https://leetcode.com/problems/minimum-absolute-difference-in-bst/
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
    int getMinimumDifference(TreeNode* root) {
        int prev = INT_MIN, ans = INT_MAX;
        inorder(root, prev, ans);
        return ans;
    }
    
    void inorder(TreeNode *root, int &prev, int &ans) {
        if (!root) return;
        inorder(root->left, prev, ans);
        if (prev != INT_MIN) ans = min(ans, root->val - prev);
        prev = root->val;
        inorder(root->right, prev, ans);
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
