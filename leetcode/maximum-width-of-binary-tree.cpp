//
//  maximum-width-of-binary-tree
//  https://leetcode.com/problems/maximum-width-of-binary-tree/
//
//  Created by smilingpoplar on 18/01/18.
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
    int widthOfBinaryTree(TreeNode* root) {
        vector<int> lefts;
        return maxWidth(root, 0, 1, lefts); // order像堆的数组表示一样从1开始，左儿子2*order，右儿子2*order+1
    }
    
    int maxWidth(TreeNode *root, int level, int order, vector<int> &lefts) {
        if (!root) return 0;
        if (level >= lefts.size()) {
            lefts.push_back(order);
        }
        
        int width = order - lefts[level] + 1;
        return max({ width, maxWidth(root->left, level + 1, order * 2, lefts), maxWidth(root->right, level + 1, order * 2 + 1, lefts) });
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
