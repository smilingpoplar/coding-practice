//
//  minimum-absolute-difference-in-bst
//  https://leetcode.com/problems/minimum-absolute-difference-in-bst/
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
    int getMinimumDifference(TreeNode* root) {
        int minDiff = INT_MAX;
        int prev = -1;
        inorder(root, prev, minDiff);
        return minDiff;
    }
    
    void inorder(TreeNode *root, int &prev, int &minDiff) {
        if (!root) return;
        inorder(root->left, prev, minDiff);
        if (prev != -1) minDiff = min(minDiff, root->val - prev);
        prev = root->val;
        inorder(root->right, prev, minDiff);
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
