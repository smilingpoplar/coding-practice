//
//  maximum-product-of-splitted-binary-tree
//  https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/
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
    int maxProduct(TreeNode* root) {
        const int MOD = 1e9 + 7;
        vector<int> sums;
        int total = dfs(root, sums);
        long ans = 0;
        for (long sum : sums) {
            ans = max(ans, sum * (total - sum));
        }
        return ans % MOD;
    }
    
    int dfs(TreeNode *root, vector<int> &sums) {
        if (!root) return 0;
        int left = dfs(root->left, sums);
        int right = dfs(root->right, sums);
        int sum = left + right + root->val;
        sums.push_back(sum);
        return sum;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
