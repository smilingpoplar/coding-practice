//
//  find-leaves-of-binary-tree
//  https://leetcode.com/problems/find-leaves-of-binary-tree/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
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
    
    int getHeight(TreeNode *root, vector<vector<int>> &ans) {
        // 高h节点放到ans[h]中，让叶节点高为0，故定义空节点高为-1
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
