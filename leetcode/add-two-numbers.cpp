//
//  add-two-numbers
//  https://leetcode.com/problems/add-two-numbers/
//
//  Created by smilingpoplar on 15/6/15.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(-1);
        ListNode *p = &dummy;
        int carry = 0;
        while (l1 || l2 || carry) {
            if (l1) carry += l1->val;
            if (l2) carry += l2->val;
            p->next = new ListNode(carry % 10);
            p = p->next;
            carry = carry / 10;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        return dummy.next;
    }
};

int main(int argc, const char * argv[]) {
    ListNode l11(2);
    ListNode l12(4);
    ListNode l13(3);
    l11.next = &l12;
    l12.next = &l13;
    ListNode l21(7);
    ListNode l22(0);
    ListNode l23(8);
    l21.next = &l22;
    l22.next = &l23;
    
    Solution solution;
    auto head = solution.addTwoNumbers(&l11, &l21);
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    
    return 0;
}
