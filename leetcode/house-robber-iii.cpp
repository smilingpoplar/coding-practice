//
//  house-robber-iii
//  https://leetcode.com/problems/house-robber-iii/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
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
    int rob(TreeNode* root) {
        // 只有两种状态：抢没抢root
        auto ans = robSub(root);
        return max(ans[0], ans[1]);
    }
    
    // 返回没抢ans[0]和抢ans[1]两种情况下的最大值
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
