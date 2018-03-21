//
//  binary-tree-longest-consecutive-sequence-ii
//  https://leetcode.com/problems/binary-tree-longest-consecutive-sequence-ii/
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
    struct Info {
        int incLen;
        int decLen;
    };
public:
    int longestConsecutive(TreeNode* root) {
        int ans = 0;
        arrowLen(root, ans);
        return ans;
    }
    
    // 从root开始往下递增或递减的路径长
    Info arrowLen(TreeNode *root, int &ans) {
        if (!root) return {0, 0};
        int incLen = 1, decLen = 1;
        if (root->left) {
            auto left = arrowLen(root->left, ans);
            if (root->left->val == root->val + 1) {
                incLen = max(incLen, left.incLen + 1);
            } else if (root->left->val == root->val - 1) {
                decLen = max(decLen, left.decLen + 1);
            }
        }
        if (root->right) {
            auto right = arrowLen(root->right, ans);
            if (root->right->val == root->val + 1) {
                incLen = max(incLen, right.incLen + 1);                
            } else if (root->right->val == root->val - 1) {
                decLen = max(decLen, right.decLen + 1);
            }
        }
        ans = max(ans, incLen + decLen - 1);
        return {incLen, decLen};
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
