//
//  find-duplicate-subtrees
//  https://leetcode.com/problems/find-duplicate-subtrees/
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> cnt;
        vector<TreeNode *> ans;        
        dfs(root, cnt, ans);
        return ans;
    }
    
    string dfs(TreeNode *root, unordered_map<string, int> &cnt, vector<TreeNode *> &ans) {
        if (!root) return "#";
        auto left = dfs(root->left, cnt, ans);
        auto right = dfs(root->right, cnt, ans);
        // 将NULL节点输出为"#"，一棵树的遍历输出唯一
        auto s = to_string(root->val) + left + right;
        cnt[s]++;
        if (cnt[s] == 2) ans.push_back(root);
        return s;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
