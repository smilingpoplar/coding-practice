//
//  pseudo-palindromic-paths-in-a-binary-tree
//  https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        // 用count的第i位记录数字x的奇偶，1<=x<=9
        int count = 0, ans = 0;
        dfs(root, count, ans);
        return ans;
    }
    
    void dfs(TreeNode *root, int count, int &ans) {
        if (!root) return;
        count ^= (1 << root->val);
        if (!root->left && !root->right) {
            ans += (count & (count - 1)) == 0; // 最多1位1
        }
        
        dfs(root->left, count, ans);
        dfs(root->right, count, ans);
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
