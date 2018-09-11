//
//  path-sum-iii
//  https://leetcode.com/problems/path-sum-iii/
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
    int pathSum(TreeNode* root, int sum) {
        if (!root) return 0;
        return searchFrom(root, sum)
            + pathSum(root->left, sum) 
            + pathSum(root->right, sum);
    }
    
    int searchFrom(TreeNode *root, int sum) {
        if (!root) return 0;
        int ans = 0;
        if (root->val == sum) ans++;
        ans += searchFrom(root->left, sum - root->val);
        ans += searchFrom(root->right, sum - root->val);
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
