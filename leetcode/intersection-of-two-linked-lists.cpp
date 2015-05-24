//
//  intersection-of-two-linked-lists
//  https://leetcode.com/problems/intersection-of-two-linked-lists/
//
//  Created by smilingpoplar on 15/5/24.
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // head1跑完链表A跑链表B，head2跑完链表B跑链表A
        // 无相交节点则同时跑到NULL，有相交节点则同时跑到相交节点
        auto head1 = headA;
        auto head2 = headB;
        while (head1 != head2) {
            head1 = head1 ? head1->next : headB;
            head2 = head2 ? head2->next : headA;
        }
        return head1;
    }
};

int main(int argc, const char * argv[]) {
    ListNode l1(1);
    ListNode l2(2);
    ListNode l3(3);
    ListNode l4(4);
    ListNode l5(5);
    ListNode l6(6);
    ListNode l7(7);
    ListNode l8(8);
    l1.next = &l2;
    l2.next = &l6;
    l6.next = &l7;
    l7.next = &l8;
    l3.next = &l4;
    l4.next = &l5;
    l5.next = &l6;
    
    Solution solution;
    auto node = solution.getIntersectionNode(&l1, &l3);
    if (node) cout << node->val;
    else cout << "NULL";
    
    return 0;
}
