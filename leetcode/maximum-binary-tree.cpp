//
//  maximum-binary-tree
//  https://leetcode.com/problems/maximum-binary-tree/
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return construct(nums, 0, (int)nums.size() - 1);
    }
    
    TreeNode* construct(vector<int>& nums, int left, int right) {
        if (left > right) return nullptr;
        int maxNum = INT_MIN, idx;
        for (int i = left; i <= right; i++) {
            if (nums[i] > maxNum) {
                maxNum = nums[i];
                idx = i;
            }
        }
        auto root = new TreeNode(maxNum);
        root->left = construct(nums, left, idx - 1);
        root->right = construct(nums, idx + 1, right);
        return root;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
