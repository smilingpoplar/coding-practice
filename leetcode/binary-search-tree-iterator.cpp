//
//  binary-search-tree-iterator
//  https://leetcode.com/problems/binary-search-tree-iterator/
//
//  Created by smilingpoplar on 15/5/20.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
    stack<TreeNode *> stk;
    
    void pushLeft(TreeNode *node) {
        while (node) {
            stk.push(node);
            node = node->left;
        }
    }
public:
    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }
    
    /** @return the next smallest number */
    int next() {
        auto node = stk.top(); stk.pop();
        pushLeft(node->right);
        return node->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !stk.empty();
    }
};

int main(int argc, const char * argv[]) {
    TreeNode t0(3);
    TreeNode t1l(1);
    t0.left = &t1l;
    TreeNode t2r(2);
    t1l.right = &t2r;
    
    BSTIterator i = BSTIterator(&t0);
    while (i.hasNext()) cout << i.next();
    
    return 0;
}
