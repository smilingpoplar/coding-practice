//
//  find-kth-to-tail
//  https://leetcode.com/problems/find-kth-to-tail/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* FindKthToTail(ListNode* pHead, int k) {
    if (k == 0 || !pHead) return nullptr;
    auto fast = pHead;
    for (int i = 0; i < k; i++) {
        if (!fast) return nullptr;
        fast = fast->next;
    }

    auto slow = pHead;
    while (fast) {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}

int main(int argc, const char* argv[]) {
    ListNode l1(1);
    ListNode l2(2);
    ListNode l3(3);
    ListNode l4(4);
    ListNode l5(5);
    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    l4.next = &l5;
    l5.next = &l3;

    Solution solution;
    cout << solution.hasCycle(&l1);

    return 0;
}
