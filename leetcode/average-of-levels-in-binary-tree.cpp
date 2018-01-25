//
//  average-of-levels-in-binary-tree
//  https://leetcode.com/problems/average-of-levels-in-binary-tree/
//
//  Created by smilingpoplar on 18/01/19.
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        if (!root) return ans;
        queue<TreeNode *> Q;
        Q.push(root);
        while (!Q.empty()) {
            int n = Q.size();
            double sum = 0;
            for (int i = 0; i < n; i++) {
                auto node = Q.front();
                Q.pop();
                sum += node->val;
                if (node->left) Q.push(node->left);
                if (node->right) Q.push(node->right);
            }
            ans.push_back(sum / n);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
