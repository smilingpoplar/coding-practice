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
        vector<vector<int>> result;
        queue<TreeNode *> queue;
        if (root) queue.push(root);
        bool rightToLeft = false;
        while (!queue.empty()) {
            vector<int> level;
            const int levelSize = (int)queue.size();
            for (int i = 0; i < levelSize; ++i) {
                auto node = queue.front();
                queue.pop();
                level.push_back(node->val);
                
                if (node->left) queue.push(node->left);
                if (node->right) queue.push(node->right);
            }
            if (rightToLeft) reverse(level.begin(), level.end());
            result.push_back(level);
            rightToLeft = !rightToLeft;
        }
        return result;
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
    auto result = solution.zigzagLevelOrder(&t0);
    for (const auto &level : result) {
        for (int num : level) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}
