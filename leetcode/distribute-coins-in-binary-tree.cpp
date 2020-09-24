//
//  distribute-coins-in-binary-tree
//  https://leetcode.com/problems/distribute-coins-in-binary-tree/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int distributeCoins(TreeNode* root) {
        int ans = 0;
        excessCoins(root, ans);
        return ans;
    }
    
    // 返回：某子树有多少多余硬币
    int excessCoins(TreeNode *root, int &ans) {
        if (!root) return 0;
        auto left = excessCoins(root->left, ans);
        auto right = excessCoins(root->right, ans);
        ans += abs(left) + abs(right); // 在本节点和左右子节点间移动多余硬币
        return left + right + root->val - 1;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
