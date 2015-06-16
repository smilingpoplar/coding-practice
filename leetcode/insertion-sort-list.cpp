//
//  insertion-sort-list
//  https://leetcode.com/problems/insertion-sort-list/
//
//  Created by smilingpoplar on 15/6/16.
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
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(-1);
        while (head) {
            auto next = head->next;
            
            auto prev = &dummy;
            while (prev->next && prev->next->val <= head->val) {
                prev = prev->next;
            }
            head->next = prev->next;
            prev->next = head;
            
            head = next;
        }
        return dummy.next;
    }
};

int main(int argc, const char * argv[]) {
    ListNode l1(2);
    ListNode l2(4);
    ListNode l3(3);
    ListNode l4(1);
    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    
    Solution solution;
    auto head = solution.insertionSortList(&l1);
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    
    return 0;
}