//
//  binary-tree-level-order-traversal-ii
//  https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode *> q;
        if (root) q.push(root);
        while (!q.empty()) {
            const int sz = q.size();
            vector<int> row;
            for (int i = 0; i < sz; i++) {
                auto node = q.front(); q.pop();
                row.push_back(node->val);
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            ans.push_back(row);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

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
    auto ans = solution.levelOrderBottom(&t0);
    for (const auto &level : ans) {
        for (int num : level) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}
