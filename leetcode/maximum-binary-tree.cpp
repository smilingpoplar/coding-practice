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
        vector<TreeNode *> stk; // 栈中是递减序列
        for (int num : nums) {
            auto curr = new TreeNode(num);
            while (!stk.empty() && num > stk.back()->val) {
                // 循环最后弹出数刚好比num小，是nums[..i]中num左边最大值，作curr的左子节点
                curr->left = stk.back();
                stk.pop_back();
            }
            // curr刚好比新栈顶stkTop小，是nums[..i]中stkTop右边最大值，作stkTop的右节点
            // 当nums[]后续的数被处理时，stkTop的右节点可能被重新设置
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
