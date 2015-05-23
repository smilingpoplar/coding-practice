//
//  reorder-list
//  https://leetcode.com/problems/reorder-list/
//
//  Created by smilingpoplar on 15/5/23.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head) return;
        // 快慢指针，将链表分成两段
        auto fast = head;
        auto slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        // 这时slow指向前半段的最后元素
        auto list2 = slow->next;
        slow->next = NULL;
        // 将list2反转
        {
            ListNode dummy(-1);
            auto current = list2;
            while (current) {
                auto next = current->next;
                current->next = dummy.next;
                dummy.next = current;
                current = next;
            }
            list2 = dummy.next;
        }
        // 将两个list交错合并
        {
            auto list1 = head;
            ListNode dummy(-1);
            ListNode *current = &dummy;
            while (list1 || list2) {
                if (list1) {
                    current->next = list1;
                    current = current->next;
                    list1 = list1->next;
                }
                if (list2) {
                    current->next = list2;
                    current = current->next;
                    list2 = list2->next;
                }
            }
            head = dummy.next;
        }
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
