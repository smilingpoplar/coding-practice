//
//  closest-binary-search-tree-value
//  https://leetcode.com/problems/closest-binary-search-tree-value/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

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
    int closestValue(TreeNode* root, double target) {
        int closest = root->val; // 已知root非空
        while (root) {
            if (abs(root->val - target) < abs(closest - target)) {
                closest = root->val;
            }
            root = (target < root->val) ? root->left : root->right;
        }
        return closest;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
