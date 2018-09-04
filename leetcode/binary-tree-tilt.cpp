//
//  binary-tree-tilt
//  https://leetcode.com/problems/binary-tree-tilt/
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
    int findTilt(TreeNode* root) {
        int ans = 0;
        getSum(root, ans);
        return ans;
    }
    
    int getSum(TreeNode* root, int &ans) {
        if (!root) return 0;
        int left = getSum(root->left, ans);
        int right = getSum(root->right, ans);
        ans += abs(left - right);
        return root->val + left + right;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
