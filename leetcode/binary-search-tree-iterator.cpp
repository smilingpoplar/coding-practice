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
public:
    // 中序遍历迭代版，用curr表示调用栈[curr,stk]的栈顶
    BSTIterator(TreeNode *root) {
        curr = root;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return curr || !stk.empty();
    }
    
    /** @return the next smallest number */
    int next() {
        while (curr || !stk.empty()) {
            while (curr) {
                stk.push(curr);
                curr = curr->left;
            }
            auto node = stk.top(); stk.pop();
            int ans = node->val;
            curr = node->right;
            return ans;
        }
        return INT_MAX;
    }
private:
    TreeNode *curr;
    stack<TreeNode *> stk;
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
