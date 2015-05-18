//
//  binary-tree-inorder-traversal
//  https://leetcode.com/problems/binary-tree-inorder-traversal/
//
//  Created by smilingpoplar on 15/5/18.
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
    vector<int> inorderTraversal(TreeNode* root) {
        // 中序遍历迭代版，用栈模拟，用curr表示调用栈[curr,stack]的栈顶
        vector<int> result;
        TreeNode *curr = root;
        vector<TreeNode *> stack;
        while (curr || !stack.empty()) {
            if (curr) { // 首先访问左子节点
                stack.push_back(curr);
                curr = curr->left;
            } else { // 当curr为空时从栈中取节点访问
                curr = stack.back();
                stack.pop_back();
                result.push_back(curr->val);
                curr = curr->right;
            }
        }
        
        return result;
    }
};

int main(int argc, const char * argv[]) {
    TreeNode t0(3);
    TreeNode t1l(1);
    t0.left = &t1l;
    TreeNode t2r(2);
    t1l.right = &t2r;
    
    Solution solution;
    auto result = solution.inorderTraversal(&t0);
    for (int num : result) {
        cout << num << " ";
    }
    
    return 0;
}
