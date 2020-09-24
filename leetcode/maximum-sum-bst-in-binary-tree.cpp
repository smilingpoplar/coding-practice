//
//  maximum-sum-bst-in-binary-tree
//  https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int maxSumBST(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
    
    // 返回{sum, min, max}
    // 空节点作左儿子时，要让"父节点的val > 空节点的max"总成立，空节点的max=INT_MIN；
    // 同理，空节点的min=INT_MAX；所以，空节点值区间[INT_MAX,INT_MIN]
    // {0,INT_MAX,INT_MIN}表示空节点，{0,INT_MIN,INT_MAX}表示无效节点
    array<int,3> dfs(TreeNode *root, int &ans) {
        if (!root) return { 0, INT_MAX, INT_MIN };
        auto left = dfs(root->left, ans);
        auto right = dfs(root->right, ans);
        if (left[2] < root->val && root->val < right[1]) {
            int sum = left[0] + root->val + right[0];
            ans = max(ans, sum);
            return { sum, min(root->val, left[1]), max(root->val, right[2]) };
        }
        return { 0, INT_MIN, INT_MAX };
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
