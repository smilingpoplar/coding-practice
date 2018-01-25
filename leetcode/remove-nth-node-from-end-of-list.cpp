//
//  remove-nth-node-from-end-of-list
//  https://leetcode.com/problems/remove-nth-node-from-end-of-list/
//
//  Created by smilingpoplar on 15/6/7.
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(-1);
        dummy.next = head;
        
        auto fast = &dummy;
        for (int i = 0; i < n && fast; i++) {
            fast = fast->next;
        }
        if (!fast) return head;
        
        auto slow = &dummy;
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        // slow是待删除节点的前驱节点
        auto toDelete = slow->next;
        slow->next = toDelete->next;
        delete toDelete;
        
        return dummy.next;
    }
};

int main(int argc, const char * argv[]) {
    auto l1 = new ListNode(1);
    auto l2 = new ListNode(2);
    auto l3 = new ListNode(3);
    auto l4 = new ListNode(4);
    auto l5 = new ListNode(5);
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    
    Solution solution;
    auto head = solution.removeNthFromEnd(l1, 2);
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    
    return 0;
}
