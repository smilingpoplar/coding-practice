//
//  populating-next-right-pointers-in-each-node
//  https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
//
//  Created by smilingpoplar on 15/6/6.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

// 完全适用 populating-next-right-pointers-in-each-node-ii 的解法

class Solution {
public:
    void connect(TreeLinkNode *root) {
        // 层序遍历，利用next指针，O(1)空间
        // 不变式：当前层已用next指针连起来了
        while (root) { // 遍历当前层
            TreeLinkNode *prev = NULL; // 下一层被处理节点的prev
            TreeLinkNode *leftMost = NULL; // 下一层的leftMost节点
            for (auto current = root; current; current = current->next) {
                if (current->left) {
                    if (prev) prev->next = current->left;
                    prev = current->left;
                }
                if (current->right) {
                    if (prev) prev->next = current->right;
                    prev = current->right;
                }
                if (!leftMost) leftMost = current->left ? current->left : current->right;
            }
            root = leftMost;
        }
    }
};

void print(TreeLinkNode *root) {
    while (root) { // 遍历当前层
        TreeLinkNode *leftMost = NULL; // 下一层的leftMost节点
        for (auto current = root; current; current = current->next) {
            cout << current->val << " ";
            if (!leftMost) leftMost = current->left ? current->left : current->right;
        }
        cout << endl;
        root = leftMost;
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
