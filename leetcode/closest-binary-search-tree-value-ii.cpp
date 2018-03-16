//
//  closest-binary-search-tree-value-ii
//  https://leetcode.com/problems/closest-binary-search-tree-value-ii/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
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
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        // 先序遍历，并维持一个k长的窗口
        queue<int> q;
        inorder(root, target, k, q);
        
        vector<int> ans;
        while (!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
    
    void inorder(TreeNode *root, double target, int k, queue<int> &q) {
        if (!root) return;
        inorder(root->left, target, k, q);
        if (q.size() < k) {
            q.push(root->val);
        } else {
            if (abs(root->val - target) < abs(q.front() - target)) {
                q.pop();
                q.push(root->val);
            }
        }
        inorder(root->right, target, k, q);
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
