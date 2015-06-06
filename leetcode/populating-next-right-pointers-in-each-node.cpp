//
//  populating-next-right-pointers-in-each-node
//  https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
//
//  Created by smilingpoplar on 15/6/6.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

/*
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // 递归
        if (!root) return;
        connect(root->left, root->right);
    }
private:
    void connect(TreeLinkNode *node, TreeLinkNode *sibling) {
        if (!node) return;
        node->next = sibling;
        connect(node->left, node->right);
        if (!sibling) return;
        connect(node->right, sibling->left);
        connect(sibling->left, sibling->right);
    }
};
*/

class Solution {
public:
    void connect(TreeLinkNode *root) {
        // 层序遍历
        queue<TreeLinkNode *> queue;
        if (root) queue.push(root);
        while (!queue.empty()) {
            TreeLinkNode *prev = NULL;
            int levelSize = (int)queue.size();
            for (int i = 0; i < levelSize; ++i) {
                auto node = queue.front();
                queue.pop();
                if (prev) prev->next = node;
                
                if (node->left) queue.push(node->left);
                if (node->right) queue.push(node->right);
                prev = node;
            }
        }
    }
};

void print(TreeLinkNode *root) {
    auto leftMost = root;
    while (leftMost) {
        auto p = leftMost;
        while (p) {
            cout << p->val << " ";
            p = p->next;
        }
        cout << endl;
        leftMost = leftMost->left;
    }
}

int main(int argc, const char * argv[]) {
    TreeLinkNode n1(1);
    TreeLinkNode n2(2);
    TreeLinkNode n3(3);
    TreeLinkNode n4(4);
    TreeLinkNode n5(5);
    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n5;
    
    Solution solution;
    solution.connect(&n1);
    print(&n1);
    
    return 0;
}
