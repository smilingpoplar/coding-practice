//
//  longest-zigzag-path-in-a-binary-tree
//  https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/
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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int longestZigZag(TreeNode* root) {
        return dfs(root)[2];
    }
    
    // 返回{leftLongest, rightLongest, subLongest}
    // 表示从当前节点向左最长、向右最长，当前子树所含最长
    array<int,3> dfs(TreeNode *root) {
        if (!root) return {-1,-1,-1};
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        int toL = 1 + left[1], toR = 1 + right[0];
        int sub = max({toL, toR, left[2], right[2]});
        return { toL, toR, sub };
    } 
};

int main(int argc, const char * argv[]) {    
    return 0;
}
