//
//  sort-list
//  https://leetcode.com/problems/sort-list/
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

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        // 归并排序
        if (!head || !head->next) return head;
        // 快慢指针
        auto fast = head;
        auto slow = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        // slow是前半链表表尾，断开成两个链表
        auto list2 = slow->next;
        slow->next = NULL;
        // 分别排序
        auto list1 = sortList(head);
        list2 = sortList(list2);
        // 归并
        ListNode dummy(-1);
        ListNode *current = &dummy;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                current->next = list1;
                current = list1;
                list1 = list1->next;
            } else {
                current->next = list2;
                current = list2;
                list2 = list2->next;
            }
        }
        current->next = list1 ? list1 : list2;
        return dummy.next;
    }
};

int main(int argc, const char * argv[]) {
    ListNode l1(2);
    ListNode l2(4);
    ListNode l3(3);
    ListNode l4(1);
    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    
    Solution solution;
    auto head = solution.sortList(&l1);
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    
    return 0;
}
