//
//  beautiful-arrangement
//  https://leetcode.com/problems/beautiful-arrangement/
//
//  Created by smilingpoplar on 17/11/30.
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
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        reverseInorder(root, sum);
        return root;
    }
    
    // sum要用引用，因为要在各方法调用间累加
    void reverseInorder(TreeNode *root, int &sum) {
        if (!root) return;
        reverseInorder(root->right, sum);
        root->val += sum;
        sum = root->val;
        reverseInorder(root->left, sum);
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
