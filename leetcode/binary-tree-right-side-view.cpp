//
//  binary-tree-right-side-view
//  https://leetcode.com/problems/binary-tree-right-side-view/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode *> q;
        if (root) q.push(root);
        while (!q.empty()) {
            const int levelSize = q.size();
            for (int i = 0; i < levelSize; i++) {
                auto node = q.front(); q.pop();
                if (i == levelSize - 1) ans.push_back(node->val);
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return ans;
    }
};

/*
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        dfs(root, 0, ans);
        return ans;
    }
    
    void dfs(TreeNode *root, int level, vector<int> &ans) {
        if (!root) return;
        if (level == ans.size()) ans.push_back(root->val);
        
        dfs(root->right, level + 1, ans);
        dfs(root->left, level + 1, ans);
    }
};
*/

int main(int argc, const char * argv[]) {
    TreeNode t0(3);
    TreeNode t1l(9);
    t0.left = &t1l;
    TreeNode t1r(20);
    t0.right = &t1r;
    TreeNode t2l(15);
    t1r.left = &t2l;
    TreeNode t2r(7);
    t1r.right = &t2r;
    
    Solution solution;
    auto result = solution.rightSideView(&t0);
    for (int num : result) {
        cout << num << " ";
    }
    
    return 0;
}
