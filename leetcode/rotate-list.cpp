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
        // 快慢指针，先让快指针跑k步
        auto fast = head;
        int length = 0;
        for (int i = 0; i < k && fast; i++) {
            fast = fast->next;
            ++length;
        }
        if (!fast) { // k >= length
            k %= length;
            if (k == 0) return head;
            // fast重跑
            fast = head;
            for (int i = 0; i < k; i++) {
                fast = fast->next;
            }
        }
        // 快慢指针同时跑，slow要取断开处之前的节点
        auto slow = head;
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        // 先把链表首尾相接
        fast->next = head;
        // 再在slow后断开
        auto newHead = slow->next;
        slow->next = NULL;
        
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
