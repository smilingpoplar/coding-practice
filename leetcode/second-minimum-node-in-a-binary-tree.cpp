//
//  second-minimum-node-in-a-binary-tree
//  https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/
//
//  Created by smilingpoplar on 18/01/18.
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
        return dfs(root, root->val);
    }
    
    // 找比min1大的最小数
    int dfs(TreeNode *root, int min1) {
        if (!root) return -1;
        if (root->val > min1) return root->val;
        
        int left = dfs(root->left, min1);
        int right = dfs(root->right, min1);
        // if (left == -1 && right == -1) return -1;
        if (left == -1) return right;
        if (right == -1) return left;
        return min(left, right);
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
