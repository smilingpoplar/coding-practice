//
//  rotate-list
//  https://leetcode.com/problems/rotate-list/
//
//  Created by smilingpoplar on 15/5/22.
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return NULL;
        // 让p2指向后半段，p2先跑k步
        auto p2 = head;
        int len = 0;
        for (int i = 0; i < k && p2; i++) {
            p2 = p2->next;
            len++;
        }
        if (!p2) { // k>=len
            k %= len;
            if (k == 0) return head;
            // k根据len调整了，p2重跑
            p2 = head;
            for (int i = 0; i < k; i++) {
                p2 = p2->next;
            }
        }
        // 同时跑，直到p1指向前半段末尾
        auto p1 = head;
        while (p2->next) {
            p2 = p2->next;
            p1 = p1->next;
        }

        p2->next = head;
        auto newHead = p1->next;
        p1->next = NULL;
        
        return newHead;
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
    auto head = solution.rotateRight(&l1, 2);
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    
    return 0;
}
