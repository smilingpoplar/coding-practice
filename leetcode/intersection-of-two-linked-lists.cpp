//
//  intersection-of-two-linked-lists
//  https://leetcode.com/problems/intersection-of-two-linked-lists/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
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
        // pa跑完链表A跑链表B，pb跑完链表B跑链表A，
        // 最终跑到同一交点（有交点到交点，无交点到NULL节点）
        auto pa = headA, pb = headB;
        while (pa != pb) {
            pa = pa ? pa->next : headB;
            pb = pb ? pb->next : headA;
        }
        return pa;
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
