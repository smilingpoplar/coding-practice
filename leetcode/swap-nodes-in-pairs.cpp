//
//  swap-nodes-in-pairs
//  https://leetcode.com/problems/swap-nodes-in-pairs/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(-1);
        dummy.next = head;
        auto prev = &dummy;

        // prev => head => next1 => next2
        while (head && head->next) {
            auto next1 = head->next;
            auto next2 = next1->next;
            prev->next = next1;
            next1->next = head;
            head->next = next2;

            prev = head;
            head = next2;
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
    auto head = solution.swapPairs(&l1);
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    
    return 0;
}
