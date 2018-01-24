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
        // 父节点是子节点中较小的，该题只要找比根节点大的数
        return largerThan(root, root->val);
    }
    
    // 找比target大的最小数
    int largerThan(TreeNode *root, int target) {
        if (!root) return -1;
        if (root->val > target) return root->val;
        
        int left = largerThan(root->left, target);
        int right = largerThan(root->right, target);
        if (left != -1 && right != -1) return min(left, right);
        if (left != -1) return left;
        return right;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
