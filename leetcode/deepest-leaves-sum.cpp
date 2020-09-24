//
//  deepest-leaves-sum
//  https://leetcode.com/problems/deepest-leaves-sum/
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
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode *> q;
        if (root) q.push(root);
        
        int ans = 0;
        while (!q.empty()) {
            ans = 0;
            for (int sz = q.size(); sz > 0; sz--) {
                auto node = q.front(); q.pop();
                ans += node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return ans;
    }    
};

int main(int argc, const char * argv[]) {    
    return 0;
}
