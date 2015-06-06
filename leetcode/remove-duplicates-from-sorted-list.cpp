//
//  remove-duplicates-from-sorted-list
//  https://leetcode.com/problems/remove-duplicates-from-sorted-list/
//
//  Created by smilingpoplar on 15/6/6.
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;
        auto prev = head;
        auto current = head->next;
        while (current) {
            auto next = current->next;
            if (current->val == prev->val) {
                prev->next = next;
                delete current;
            } else {
                prev = current;
            }
            current = next;
        }
        return head;
    }
};

int main(int argc, const char * argv[]) {
    ListNode *l1 = new ListNode(1);
    ListNode *l2 = new ListNode(1);
    ListNode *l3 = new ListNode(2);
    ListNode *l4 = new ListNode(2);
    ListNode *l5 = new ListNode(3);
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    
    Solution solution;
    auto head = solution.deleteDuplicates(l1);
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    
    return 0;
}
