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

class Solution {
public:
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
};
