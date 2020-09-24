//
//  convert-binary-search-tree-to-doubly-linked-list
//  https://leetcode.com/problems/convert-binary-search-tree-to-doubly-linked-list/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

/**
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 * 
 * class DoublyListNode {
 * public:
 *     int val;
 *     DoublyListNode *next, *prev;
 *     DoublyListNode(int val) {
 *         this->val = val;
           this->prev = this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    DoublyListNode * bstToDoublyList(TreeNode * root) {
        stack<TreeNode *> stk;
        auto curr = root;
        DoublyListNode *head = NULL, *prev = NULL;
        while (curr || !stk.empty()) {
            while (curr) {
                stk.push(curr);
                curr = curr->left;
            }
            auto node = stk.top(); stk.pop();
            // 中序遍历访问node
            auto dln = new DoublyListNode(node->val);
            if (!head) head = dln;
            if (prev) prev->next = dln;
            dln->prev = prev;
            prev = dln;
            
            curr = node->right;
        }
        return head;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
