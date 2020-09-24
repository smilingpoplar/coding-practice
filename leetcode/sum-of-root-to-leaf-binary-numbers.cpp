//
//  sum-of-root-to-leaf-binary-numbers
//  https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        int cur = 0, ans = 0;
        dfs(root, cur, ans);
        return ans;        
    }
    
    void dfs(TreeNode *root, int cur, int &ans) {
        if (!root) return;
        cur = (cur << 1) + root->val;
        if (!root->left && !root->right) {
            ans += cur;
            return;
        }
        dfs(root->left, cur, ans);
        dfs(root->right, cur, ans);
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
