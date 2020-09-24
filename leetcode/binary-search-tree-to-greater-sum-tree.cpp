//
//  binary-search-tree-to-greater-sum-tree
//  https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/
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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        reverseInorder(root, sum);
        return root;
    }
    
    void reverseInorder(TreeNode *root, int &sum) {
        if (!root) return;
        reverseInorder(root->right, sum);
        sum += root->val;
        root->val = sum;
        reverseInorder(root->left, sum);
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
