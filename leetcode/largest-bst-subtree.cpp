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
    struct BstInfo {
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
    
    BstInfo checkBst(TreeNode *root, int &ans) {
        // 空节点算bst，值范围为空 [INT_MAX,INT_MIN]
        // 因为值范围要使它作为左儿子时，父节点的 root->val > upper 总成立，因此upper=INT_MIN；同理，lower=INT_MAX
        if (!root) return { 0, INT_MAX, INT_MIN };
        auto left = checkBst(root->left, ans);
        auto right = checkBst(root->right, ans);
        if (left.size == -1 || right.size == -1 || left.upper >= root->val || root->val >= right.lower) {
            return { -1, 0, 0 }; // 以root为根的子树不是bst，size=-1
        }
        int size = left.size + 1 + right.size;
        ans = max(ans, size);
        int lower = min(left.lower, root->val); // 正常是left.lower < root->val的，但空节点的left.lower=INT_MAX，所以用min()处理
        int upper = max(right.upper, root->val); // 同理，用max()处理空节点的情况
        return { size, lower, upper };
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
