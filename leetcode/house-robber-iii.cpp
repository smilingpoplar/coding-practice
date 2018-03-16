//
//  house-robber-iii
//  https://leetcode.com/problems/house-robber-iii/
//
//  Created by smilingpoplar on 15/6/7.
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
/*
class Solution {
public:
    int rob(TreeNode* root) {
        unordered_map<TreeNode *, int> memo;
        return robSub(root, memo);
    }
    
    int robSub(TreeNode *root, unordered_map<TreeNode *, int> &memo) {
        if (!root) return 0;
        if (memo.count(root)) return memo[root];
        
        int robRoot = root->val;
        if (root->left) {
            robRoot += robSub(root->left->left, memo);
            robRoot += robSub(root->left->right, memo);
        }
        if (root->right) {
            robRoot += robSub(root->right->left, memo);
            robRoot += robSub(root->right->right, memo);
        }
        memo[root] = max(robRoot, robSub(root->left, memo) + robSub(root->right, memo));
        return memo[root];
    }
};
*/

class Solution {
public:
    // https://leetcode.com/problems/house-robber-iii/discuss/79330/Step-by-step-tackling-of-the-problem
    int rob(TreeNode* root) {
        // 问题只有两种状态，抢没抢root，也只需子问题的这两种状态
        auto ans = robSub(root);
        return max(ans[0], ans[1]);
    }
    
    // 设子问题返回没抢ans[0]和抢ans[1]两种情况下各自的最大值
    vector<int> robSub(TreeNode *root) {
        if (!root) return { 0, 0 };
        auto left = robSub(root->left);
        auto right = robSub(root->right);
        int noRobRoot = max(left[0], left[1]) + max(right[0], right[1]);
        int robRoot = root->val + left[0] + right[0];
        return { noRobRoot, robRoot };
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
