//
//  binary-tree-maximum-path-sum
//  https://leetcode.com/problems/binary-tree-maximum-path-sum/
//
//  Created by smilingpoplar on 15/5/20.
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
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        arrowSum(root, ans);
        return ans;
    }

    // 返回从root往下的最大路径和
    int arrowSum(TreeNode *root, int &ans) {
        if (!root) return 0;
        int left = arrowSum(root->left, ans);
        int right = arrowSum(root->right, ans);
        int arrow = root->val + max({0, left, right});
        
        // 经过root的最大路径和
        int pathSum = root->val + max(0, left) + max(0, right);
        ans = max(ans, pathSum);
        
        return arrow;
    }
};

int main(int argc, const char * argv[]) {
    TreeNode t0(3);
    TreeNode t1l(1);
    t0.left = &t1l;
    TreeNode t2r(2);
    t1l.right = &t2r;
    
    Solution solution;
    cout << solution.maxPathSum(&t0);
    
    return 0;
}
