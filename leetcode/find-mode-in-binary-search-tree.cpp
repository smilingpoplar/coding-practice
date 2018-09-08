//
//  find-mode-in-binary-search-tree
//  https://leetcode.com/problems/find-mode-in-binary-search-tree/
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
    vector<int> findMode(TreeNode* root) {
        // bst中找众数，先序遍历找连续出现最多的数
        vector<int> ans;
        int prev = INT_MIN;
        int count = 0, maxCount = INT_MIN;
        inorder(root, prev, count, maxCount, ans);
        return ans;
    }

    void inorder(TreeNode *root, int &prev, int &count, int &maxCount, vector<int> &ans) {
        if (!root) return;
        inorder(root->left, prev, count, maxCount, ans);

        if (root->val != prev) count = 1;
        else count++;
        if (count > maxCount) {
            maxCount = count;
            ans = { root->val };
        } else if (count == maxCount) {
            ans.push_back(root->val);
        }
        
        prev = root->val;
        inorder(root->right, prev, count, maxCount, ans);
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
