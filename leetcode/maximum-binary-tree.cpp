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
        // 从左往右扫描，假设已构造好子问题nums[0..i-1]，现在处理nums[i]。
        // 让nums[i]对应下一个更大的数，'nums[i] > stk.back()->val'时弹栈顶，
        // 最后弹出的数是nums[i]左边小于<nums[i]的最大数，同时nums[i]是新栈顶右边<新栈顶的最大数。
        // 找下一个更大的数 <=> 留下的是递减栈 => 最大值在stk.front()
        vector<TreeNode *> stk;
        for (int num : nums) {
            auto curr = new TreeNode(num);
            while (!stk.empty() && num > stk.back()->val) {
                curr->left = stk.back();
                stk.pop_back();
            }

            if (!stk.empty()) stk.back()->right = curr;
            stk.push_back(curr);
        }
        return !stk.empty() ? stk.front() : NULL;
    }
};

/*
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
*/

int main(int argc, const char * argv[]) {    
    return 0;
}
