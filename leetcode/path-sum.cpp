//
//  path-sum
//  https://leetcode.com/problems/path-sum/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (!root) return false;
        if (!root->left && !root->right) return root->val == sum;
        
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};

int main(int argc, const char * argv[]) {
    TreeNode t0(5);
    TreeNode t1l(2);
    t0.left = &t1l;
    TreeNode t1r(8);
    t0.right = &t1r;
    
    Solution solution;
    cout << solution.hasPathSum(&t0, 13);
    
    return 0;
}
