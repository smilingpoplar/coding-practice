//
//  validate-binary-search-tree
//  https://leetcode.com/problems/validate-binary-search-tree/
//
//  Created by smilingpoplar on 15/5/23.
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

/* 用long类型来躲避烦人的INT_MIN,INT_MAX边界测试，有些tricky
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }
private:
    // bst的所有节点 (min,max)
    bool isValidBST(TreeNode *root, long min, long max) {
        if (!root) return true;
        return min < root->val && root->val < max
        && isValidBST(root->left, min, root->val)
        && isValidBST(root->right, root->val, max);
    }
};
*/

// 更一般地，用中序遍历法，没有INT_MIN,INT_MAX边界值的问题，bst的中序遍历应是个单调递增序列
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        // 中序遍历，用current表示调用栈[current,stack]的栈顶
        auto current = root;
        vector<TreeNode *> stack;
        TreeNode *prev = NULL;
        while (current || !stack.empty()) {
            if (current) {
                stack.push_back(current);
                current = current->left;
            } else {
                current = stack.back();
                stack.pop_back();
                
                if (prev && current->val <= prev->val) return false;
                prev = current;
                
                current = current->right;
            }
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    TreeNode t0(3);
    TreeNode t1l(1);
    t0.left = &t1l;
    TreeNode t2r(2);
    t1l.right = &t2r;
    
    Solution solution;
    cout << solution.isValidBST(&t0);
    
    return 0;
}
