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
        auto p1 = &dummy1;
        ListNode dummy2(-1); // list2 >= x
        auto p2 = &dummy2;
        while (head) {
            if (head->val < x) {
                p1->next = head;
                p1 = head;
            } else {
                p2->next = head;
                p2 = head;
            }
            head = head->next;
        }
        p1->next = dummy2.next;
        p2->next = NULL;
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
