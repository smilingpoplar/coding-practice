//
//  delete-nodes-and-return-forest
//  https://leetcode.com/problems/delete-nodes-and-return-forest/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> toDel(begin(to_delete), end(to_delete));
        vector<TreeNode*> ans;
        root = dfs(root, toDel, ans);
        if (root) ans.push_back(root);
        return ans;
    }
    
    TreeNode* dfs(TreeNode *root, unordered_set<int> &toDel, vector<TreeNode*> &ans) {
        if (!root) return nullptr;
        root->left = dfs(root->left, toDel, ans);
        root->right = dfs(root->right, toDel, ans);
        if (!toDel.count(root->val)) return root;
        
        if (root->left) ans.push_back(root->left);
        if (root->right) ans.push_back(root->right);
        return nullptr;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
