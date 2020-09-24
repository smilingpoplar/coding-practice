//
//  remove-linked-list-elements
//  https://leetcode.com/problems/remove-linked-list-elements/
//
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(-1);
        dummy.next = head;
        
        auto p = &dummy;
        while (p->next) {
            if (p->next->val == val) {
                auto toDelete = p->next;
                p->next = toDelete->next;
                delete toDelete;
            } else {
                p = p->next;
            }
        }
        return dummy.next;
    }
};

int main(int argc, const char * argv[]) {
    auto l1 = new ListNode(1);
    auto l2 = new ListNode(6);
    auto l3 = new ListNode(3);
    auto l4 = new ListNode(6);
    auto l5 = new ListNode(5);
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    
    Solution solution;
    auto head = solution.removeElements(l1, 6);
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    
    return 0;
}
