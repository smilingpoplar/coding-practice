//
//  second-minimum-node-in-a-binary-tree
//  https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/
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
    int findSecondMinimumValue(TreeNode* root) {
        if (!root) return -1;
        int min1 = root->val, min2 = INT_MAX;
        dfs(root, min1, min2);
        return min2 != INT_MAX ? min2 : -1;
    }
    
    // 已知该树中，root->val >= min1
    void dfs(TreeNode* root, int min1, int &min2) {
        if (!root) return;
        if (root->val == min1) {
            dfs(root->left, min1, min2);
            dfs(root->right, min1, min2);
        } else if (root->val < min2) {
            min2 = root->val;
        }
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
