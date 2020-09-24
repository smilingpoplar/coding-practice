//
//  closest-binary-search-tree-value
//  https://leetcode.com/problems/closest-binary-search-tree-value/
//
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
        int ans = root->val; // 已知root非空
        while (root) { // 去往更接近target的路上
            if (abs(root->val - target) < abs(ans - target)) {
                ans = root->val;
            }
            root = (target < root->val) ? root->left : root->right;
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
