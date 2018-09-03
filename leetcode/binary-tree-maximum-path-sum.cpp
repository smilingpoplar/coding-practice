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

    int arrowSum(TreeNode *root, int &ans) {
        // 从root往左向下或往右向下的路径和
        if (!root) return 0;
        int leftSub = arrowSum(root->left, ans);
        int rightSub = arrowSum(root->right, ans);
        int arrow = root->val + max({0, leftSub, rightSub});
        
        // 后序遍历，更新ans
        int pathSum = root->val + max(0, leftSub) + max(0, rightSub);
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
