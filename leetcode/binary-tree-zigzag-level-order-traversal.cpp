//
//  binary-tree-zigzag-level-order-traversal
//  https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
//
//  Created by smilingpoplar on 15/5/13.
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode *> Q;
        if (root) Q.push(root);
        bool toRight = true;
        while (!Q.empty()) {
            vector<int> row;
            for (int sz = Q.size(); sz > 0; sz--) {
                auto node = Q.front(); Q.pop();
                row.push_back(node->val);
                
                if (node->left) Q.push(node->left);
                if (node->right) Q.push(node->right);
            }
            if (!toRight) reverse(row.begin(), row.end());
            ans.push_back(row);
            toRight = !toRight;
        }
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
    auto ans = solution.zigzagLevelOrder(&t0);
    for (const auto &level : ans) {
        for (int num : level) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}
