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
        checkBst(root, ans);
        return ans;
    }
    
    Info checkBst(TreeNode *root, int &ans) {
        // 空节点算bst，值区间为[INT_MAX,INT_MIN]
        // 当空节点作左儿子时，父节点的root->val > upper总成立，故upper=INT_MIN；同理，lower=INT_MAX。
        if (!root) return { 0, INT_MAX, INT_MIN };
        auto left = checkBst(root->left, ans);
        auto right = checkBst(root->right, ans);
        if (left.size == -1 || right.size == -1 || left.upper >= root->val || root->val >= right.lower) {
            return { -1, 0, 0 }; // 以root为根的子树不是bst，size=-1
        }
        int size = left.size + 1 + right.size;
        ans = max(ans, size);
        int lower = min(left.lower, root->val); // 正常是left.lower < root->val，但空节点例外
        int upper = max(right.upper, root->val);
        return { size, lower, upper };
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
