//
//  print-binary-tree
//  https://leetcode.com/problems/print-binary-tree/
//
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
    vector<vector<string>> printTree(TreeNode* root) {
        // h * 2^h-1
        int h = getHeight(root);
        int w = (1 << h) - 1;
        vector<vector<string>> matrix(h, vector<string>(w));
        print(root, matrix, 0, 0, w - 1);
        return matrix;
    }
    
    int getHeight(TreeNode *root) {
        if (!root) return 0;
        return 1 + max(getHeight(root->left), getHeight(root->right));
    }
    
    void print(TreeNode *root, vector<vector<string>> &matrix, 
               int row, int left, int right) {
        if (!root) return;
        int col = (left + right) / 2;
        matrix[row][col] = to_string(root->val);
        print(root->left, matrix, row + 1, left, col - 1);
        print(root->right, matrix, row + 1, col + 1, right);
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
