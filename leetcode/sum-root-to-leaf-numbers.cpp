//
//  sum-root-to-leaf-numbers
//  https://leetcode.com/problems/sum-root-to-leaf-numbers/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        dfs(root, 0, ans);
        return ans;
    }

    void dfs(TreeNode *root, int num, int &ans) {
        if (!root) return;
        
        num = num * 10 + root->val;
        if (!root->left && !root->right) ans += num;
        dfs(root->left, num, ans);
        dfs(root->right, num, ans);
    }
};

int main(int argc, const char * argv[]) {
    TreeNode t0(1);
    TreeNode t1l(2);
    t0.left = &t1l;
    TreeNode t1r(3);
    t0.right = &t1r;
    
    Solution solution;
    cout << solution.sumNumbers(&t0);
    
    return 0;
}
