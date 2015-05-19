//
//  binary-search-tree-iterator
//  https://leetcode.com/problems/binary-search-tree-iterator/
//
//  Created by smilingpoplar on 15/5/20.
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

class BSTIterator {
public:
    // 中序遍历迭代版，用current表示调用栈[current,stack]的栈顶
    BSTIterator(TreeNode *root) {
        current = root;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return current || !stack.empty();
    }
    
    /** @return the next smallest number */
    int next() {
        while (current || !stack.empty()) {
            if (current) {
                stack.push_back(current);
                current = current->left;
            } else {
                current = stack.back();
                stack.pop_back();
                int result = current->val;
                current = current->right;
                return result;
            }
        }
        return INT_MAX;
    }
private:
    TreeNode *current;
    vector<TreeNode *> stack;
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
