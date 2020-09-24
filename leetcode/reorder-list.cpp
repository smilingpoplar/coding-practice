//
//  reorder-list
//  https://leetcode.com/problems/reorder-list/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head) return;
        // 快慢指针，slow将指向较长前半段的尾节点
        auto fast = head->next, slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        auto l2 = reverse(slow->next);
        slow->next = NULL;
        merge(head, l2);
    }
    
    ListNode* reverse(ListNode *head) {
        ListNode* list = NULL;
        while (head) {
            auto next = head->next;
            head->next = list;
            list = head;
            head = next;
        }
        return list;
    }
    
    ListNode* merge(ListNode *l1, ListNode *l2) {
        ListNode dummy(-1);
        ListNode *p = &dummy;
        while (l1 && l2) {
            p->next = l1;
            p = l1;
            l1 = l1->next;
            
            p->next = l2;
            p = l2;
            l2 = l2->next;
        }
        p->next = l1 ? l1 : l2;
        return dummy.next;
    }
};

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
    solution.reorderList(&l1);
    auto head = &l1;
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    
    return 0;
}
