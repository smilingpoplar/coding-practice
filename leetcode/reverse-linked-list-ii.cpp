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
        if (!(head && 1 <= m && m <= n)) return NULL;
        ListNode dummy(-1);
        dummy.next = head;
        
        auto prev = &dummy;
        for (int i = 1; i < m; ++i) {
            prev = prev->next;
            if (!prev) return NULL;
        }
        auto p = prev->next;
        auto nNode = p;
        for (int i = m; i <= n; ++i) {
            if (!p) return NULL;
            auto next = p->next;
            p->next = prev->next;
            prev->next = p;
            p = next;
        }
        nNode->next = p;
        
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
