//
//  cousins-in-binary-tree
//  https://leetcode.com/problems/cousins-in-binary-tree/
//
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
    bool isCousins(TreeNode* root, int x, int y) {
        // x或y => {depth, parent}
        unordered_map<int, pair<int, TreeNode *>> mp; 
        dfs(root, x, y, 0, NULL, mp);
        return mp.count(x) && mp.count(y) 
            && mp[x].first == mp[y].first && mp[x].second != mp[y].second;
    }
    
    void dfs(TreeNode* root, int x, int y, 
             int depth, TreeNode* parent,
             unordered_map<int, pair<int, TreeNode *>> &mp) {
        if (!root) return;
        if (root->val == x || root->val == y) {
            mp[root->val] = {depth, parent};
        }
        dfs(root->left, x, y, depth + 1, root, mp);
        dfs(root->right, x, y, depth + 1, root, mp);
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
