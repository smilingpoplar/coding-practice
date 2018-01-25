//
//  populating-next-right-pointers-in-each-node-ii
//  https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
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

/*
#include <queue>

class Solution {
public:
    void connect(TreeLinkNode *root) {
        // 层序遍历，用队列，O(n)空间
        queue<TreeLinkNode *> queue;
        if (root) queue.push(root);
        while (!queue.empty()) {
            TreeLinkNode *prev = NULL;
            int levelSize = (int)queue.size();
            for (int i = 0; i < levelSize; i++) {
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
*/

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
    TreeLinkNode n7(7);
    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n5;
    n3.right = &n7;
    
    Solution solution;
    solution.connect(&n1);
    print(&n1);
    
    return 0;
}
