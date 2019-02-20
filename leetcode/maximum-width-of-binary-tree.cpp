//
//  maximum-width-of-binary-tree
//  https://leetcode.com/problems/maximum-width-of-binary-tree/
//
//  Created by smilingpoplar on 18/01/18.
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
    int widthOfBinaryTree(TreeNode* root) {
        vector<int> leftMost; // 各层最左节点的id
        int ans = INT_MIN;
        dfs(root, 0, 1, leftMost, ans);
        return ans;
    }
    
    void dfs(TreeNode *root, int depth, int id, vector<int> &leftMost, int &ans) {
        if (!root) return;
        if (depth == leftMost.size()) leftMost.push_back(id);
        
        int width = id - leftMost[depth] + 1;
        ans = max(ans, width);
        dfs(root->left, depth + 1, id * 2, leftMost, ans);
        dfs(root->right, depth + 1, id * 2 + 1, leftMost, ans);
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
