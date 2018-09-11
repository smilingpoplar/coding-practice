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
        vector<int> leftmost;
        int ans = INT_MIN;
        dfs(root, 0, 0, leftmost, ans);
        return ans;
    }
    
    void dfs(TreeNode *root, int depth, int order, vector<int> &leftmost, int &ans) {
        if (!root) return;
        if (depth == leftmost.size()) leftmost.push_back(order);
        
        int width = order - leftmost[depth] + 1;
        ans = max(ans, width);
        dfs(root->left, depth + 1, order * 2, leftmost, ans);
        dfs(root->right, depth + 1, order * 2 + 1, leftmost, ans);
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
