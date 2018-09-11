//
//  add-one-row-to-tree
//  https://leetcode.com/problems/add-one-row-to-tree/
//
//  Created by smilingpoplar on 17/12/03.
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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        TreeNode dummy(0);
        dummy.left = root;
        insert(0, &dummy, v, d);
        return dummy.left;
    }
    
    void insert(int depth, TreeNode* root, int v, int d) {
        // 找到d-1层，在其子节点插入
        if (!root) return;
        if (depth < d - 1) {
            insert(depth + 1, root->left, v, d);
            insert(depth + 1, root->right, v, d);
        } else {
            auto ln = new TreeNode(v);
            ln->left = root->left;
            root->left = ln;
            
            auto rn = new TreeNode(v);
            rn->right = root->right;
            root->right = rn;                
        }
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
