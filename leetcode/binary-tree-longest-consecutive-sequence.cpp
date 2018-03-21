//
//  binary-tree-longest-consecutive-sequence
//  https://leetcode.com/problems/binary-tree-longest-consecutive-sequence/
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
    int longestConsecutive(TreeNode* root) {
        int ans = 0;
        dfs(root, NULL, 0, ans);
        return ans;
    }
    
    void dfs(TreeNode *root, TreeNode *parent, int length, int &ans) { // length是到parent的路径长
        if (!root) return;
        if (parent && parent->val + 1 == root->val) length++;
        else length = 1;
        ans = max(ans, length);
        
        dfs(root->left, root, length, ans);
        dfs(root->right, root, length, ans);        
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
