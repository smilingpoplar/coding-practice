//
//  binary-tree-right-side-view
//  https://leetcode.com/problems/binary-tree-right-side-view/
//
//  Created by smilingpoplar on 15/5/19.
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
        queue<TreeNode *> Q;
        if (root) Q.push(root);
        while (!Q.empty()) {
            const int levelSize = Q.size();
            for (int i = 0; i < levelSize; i++) {
                auto node = Q.front();
                Q.pop();
                if (i == levelSize - 1) ans.push_back(node->val);
                
                if (node->left) Q.push(node->left);
                if (node->right) Q.push(node->right);
            }
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
    auto result = solution.rightSideView(&t0);
    for (int num : result) {
        cout << num << " ";
    }
    
    return 0;
}
