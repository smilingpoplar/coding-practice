//
//  binary-tree-longest-consecutive-sequence-ii
//  https://leetcode.com/problems/binary-tree-longest-consecutive-sequence-ii/
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
    struct Info {
        int incCnt;
        int decCnt;
    };
public:
    int longestConsecutive(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
    
    // 从root开始往下递增和递减的节点数
    Info dfs(TreeNode *root, int &ans) {
        if (!root) return {0, 0};
        auto left = dfs(root->left, ans);
        auto right = dfs(root->right, ans);

        int incCnt = 1, decCnt = 1;        
        if (root->left) {
            if (root->left->val == root->val + 1) {
                incCnt = max(incCnt, left.incCnt + 1);
            } else if (root->left->val == root->val - 1) {
                decCnt = max(decCnt, left.decCnt + 1);
            }
        }
        if (root->right) {
            if (root->right->val == root->val + 1) {
                incCnt = max(incCnt, right.incCnt + 1);
            } else if (root->right->val == root->val - 1) {
                decCnt = max(decCnt, right.decCnt + 1);
            }
        }
        ans = max(ans, incCnt + decCnt - 1);
        return {incCnt, decCnt};
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
