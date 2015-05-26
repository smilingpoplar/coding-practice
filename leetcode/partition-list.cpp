//
//  partition-list
//  https://leetcode.com/problems/partition-list/
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
    ListNode* partition(ListNode* head, int x) {
        ListNode dummy1(-1); // list1 < x
        ListNode *curr1 = &dummy1;
        ListNode dummy2(-1); // list2 >= x
        ListNode *curr2 = &dummy2;
        for (auto p = head; p; p = p->next) {
            if (p->val < x) {
                curr1->next = p;
                curr1 = p;
            } else {
                curr2->next = p;
                curr2 = p;
            }
        }
        curr1->next = dummy2.next;
        curr2->next = NULL;
        return dummy1.next;
    }
};

int main(int argc, const char * argv[]) {
    ListNode l2(2);
    ListNode l1(1);
    l2.next = &l1;
    
    Solution solution;
    auto head = solution.partition(&l2, 2);
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    
    return 0;
}
