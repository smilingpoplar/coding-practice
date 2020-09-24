//
//  construct-string-from-binary-tree
//  https://leetcode.com/problems/construct-string-from-binary-tree/
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
    string tree2str(TreeNode* t) {
        if (!t) return "";
        ostringstream oss;
        oss << t->val;
        // 右非空时左都得输出括号
        if (t->right) {
            oss << "(" << tree2str(t->left) << ")" << "(" << tree2str(t->right) << ")";
        } else if (t->left) {
            oss << "(" << tree2str(t->left) << ")";
        }
        return oss.str();
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
