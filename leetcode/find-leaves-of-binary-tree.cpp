//
//  find-leaves-of-binary-tree
//  https://leetcode.com/problems/find-leaves-of-binary-tree/
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
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> ans;
        getHeight(root, ans);
        return ans;
    }
    
    // 叶节点高为0，越往上越高，高h节点放到ans[h]中
    int getHeight(TreeNode *root, vector<vector<int>> &ans) {
        if (!root) return -1;
        auto left = getHeight(root->left, ans);
        auto right = getHeight(root->right, ans);
        int h = 1 + max(left, right);
        
        if (h == ans.size()) ans.push_back({});
        ans[h].push_back(root->val);
        return h;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
