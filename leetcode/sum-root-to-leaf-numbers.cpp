//
//  sum-root-to-leaf-numbers
//  https://leetcode.com/problems/sum-root-to-leaf-numbers/
//
//  Created by smilingpoplar on 15/5/26.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return sumNumber(root, 0);
    }
private:
    int sumNumber(TreeNode *root, int prefix) {
        if (!root) return 0;
        prefix = prefix * 10 + root->val;
        if (!root->left && !root->right) return prefix;
        return sumNumber(root->left, prefix) + sumNumber(root->right, prefix);
    }
};

int main(int argc, const char * argv[]) {
    TreeNode t0(1);
    TreeNode t1l(2);
    t0.left = &t1l;
    TreeNode t1r(3);
    t0.right = &t1r;
    
    Solution solution;
    cout << solution.sumNumbers(&t0);
    
    return 0;
}
