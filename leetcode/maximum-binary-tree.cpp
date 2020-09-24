//
//  maximum-binary-tree
//  https://leetcode.com/problems/maximum-binary-tree/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
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
        // 以最大值为根构造二叉树，正好对应问题"找下一个更大数"
        // 从左往右扫描，当前数num>stk.top()时弹栈顶。
        // 1. 最后的弹出数是num左边<num的最大数，是num的左子节点；
        // 2. 新栈顶是num左边>num的最小数，
        //    => num是新栈顶右边<新栈顶的最大数，是新栈顶的右子节点。
        // 最后，找下一个更大的数 => 留下递减栈 => 最大值在stk[0]
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
