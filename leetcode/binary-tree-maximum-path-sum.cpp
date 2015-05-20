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
        // 通过某节点的maxPathSum有三种：1.往左子树延伸 2.往右子树延伸 3.跨左右子树
        // 都需要求子树中的子问题：从root开始的路径的maxSubPathSum
        int maxPathSum = INT_MIN;
        maxSubPathSum(root, maxPathSum);
        return maxPathSum;
    }
private:
    int maxSubPathSum(TreeNode *root, int &maxPathSum) {
        if (!root) return 0;
        int left = maxSubPathSum(root->left, maxPathSum);
        int right = maxSubPathSum(root->right, maxPathSum);
        int maxSubPathSum = root->val + max(0, max(left, right));
        
        // 正好在递归过程中求maxPathSum
        int pathSum = root->val;
        if (left > 0) pathSum += left;
        if (right > 0) pathSum += right;
        maxPathSum = max(maxPathSum, pathSum);
        
        return maxSubPathSum;
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
