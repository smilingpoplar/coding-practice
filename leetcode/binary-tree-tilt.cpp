//
//  binary-tree-tilt
//  https://leetcode.com/problems/binary-tree-tilt/
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
    int findTilt(TreeNode* root) {
        int tilt = 0;
        sum(root, tilt);
        return tilt;
    }
    
    int sum(TreeNode* root, int &tilt) {
        if (!root) return 0;
        int leftSum = sum(root->left, tilt);
        int rightSum = sum(root->right, tilt);
        tilt += abs(leftSum - rightSum);
        return root->val + leftSum + rightSum;
    }
    
};

int main(int argc, const char * argv[]) {    
    return 0;
}
