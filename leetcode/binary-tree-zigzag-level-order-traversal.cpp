//
//  binary-tree-zigzag-level-order-traversal
//  https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
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
        // 正常的分层遍历，输出时将元素放到该层从左往右或从右往左的对应位置
        vector<vector<int>> ans;
        queue<TreeNode *> q;
        if (root) q.push(root);
        bool toRight = true;
        while (!q.empty()) {
            int sz = q.size();
            vector<int> row(sz);
            for (int i = 0; i < sz; i++) {
                auto node = q.front(); q.pop();
                int idx = toRight ? i : sz - 1 - i;
                row[idx] = node->val;
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
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
