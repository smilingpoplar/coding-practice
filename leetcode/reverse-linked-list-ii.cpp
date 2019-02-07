//
//  reverse-linked-list-ii
//  https://leetcode.com/problems/reverse-linked-list-ii/
//
//  Created by smilingpoplar on 15/5/20.
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (!head) return NULL;
        
        ListNode dummy(-1);
        dummy.next = head;
        auto prev = &dummy;
        for (int i = 1; i < m; i++) prev = prev->next;

        // 组头是反转后的组尾，将[m+1..n]的节点插入prev之后
        auto tail = prev->next, curr = tail->next;
        for (int i = m + 1; i <= n; i++) {
            tail->next = curr->next;
            curr->next = prev->next;
            prev->next = curr;
            curr = tail->next;
        }
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
    auto head = solution.reverseBetween(&l1, 1, 2);
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    
    return 0;
}
