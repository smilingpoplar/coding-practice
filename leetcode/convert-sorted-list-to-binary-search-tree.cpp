//
//  convert-sorted-list-to-binary-search-tree
//  https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
//
//  Created by smilingpoplar on 15/6/23.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode *head) {
        if (!head) return NULL;
        // 快慢指针，slow指向较短后半段的头节点
        auto fast = head, slow = head;
        ListNode *prev = NULL;
        while (fast && fast->next) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        auto root = new TreeNode(slow->val);
        if (prev) {
            prev->next = NULL;
            root->left = sortedListToBST(head);
        }
        root->right = sortedListToBST(slow->next);
        
        return root;
    }
};

void print(TreeNode *root) {
    if (!root) return;
    print(root->left);
    cout << root->val << " ";
    print(root->right);
}

int main(int argc, const char * argv[]) {
    ListNode l1(1);
    ListNode l2(2);
    ListNode l3(3);
    ListNode l4(4);
    ListNode l5(5);
    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    l4.next = &l5;
    
    Solution solution;
    auto root = solution.sortedListToBST(&l1);
    print(root);
    
    return 0;
}
