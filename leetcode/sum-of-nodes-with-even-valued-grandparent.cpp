//
//  sum-of-nodes-with-even-valued-grandparent
//  https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int sumEvenGrandparent(TreeNode* root) {
        int ans = 0;
        dfs(root, false, false, ans);
        return ans;
    }
    
    void dfs(TreeNode *root, bool pEven, bool gpEven, int &ans) {
        if (!root) return;
        if (gpEven) ans += root->val;
        bool even = root->val % 2 == 0;
        dfs(root->left, even, pEven, ans);
        dfs(root->right, even, pEven, ans);
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
