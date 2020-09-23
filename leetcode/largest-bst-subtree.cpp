//
//  largest-bst-subtree
//  https://leetcode.com/problems/largest-bst-subtree/
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
class Solution {
    struct Info {
        int size;
        int lower;
        int upper;
    };
public:
    int largestBSTSubtree(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
    
    Info dfs(TreeNode *root, int &ans) {
        // 空节点作左儿子时，要让"父节点的val > 空节点的upper"总成立，故空节点upper=INT_MIN；
        // 同理，空节点lower=INT_MAX；所以，空节点值区间[INT_MAX,INT_MIN]
        if (!root) return { 0, INT_MAX, INT_MIN };
        auto left = dfs(root->left, ans);
        auto right = dfs(root->right, ans);
        if (left.size == -1 || right.size == -1 || left.upper >= root->val || root->val >= right.lower) {
            return { -1, 0, 0 }; // 以root为根的子树不是bst，size=-1
        }
        int size = left.size + 1 + right.size;
        ans = max(ans, size);
        int lower = min(left.lower, root->val); // 需要考虑空节点的情况
        int upper = max(right.upper, root->val);
        return { size, lower, upper };
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
