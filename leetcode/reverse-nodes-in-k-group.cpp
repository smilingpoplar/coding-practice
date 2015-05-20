//
//  reverse-nodes-in-k-group
//  https://leetcode.com/problems/reverse-nodes-in-k-group/
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || !head->next || k < 2) return head;
        ListNode dummy(-1);
        dummy.next = head;
        
        auto prev = &dummy;
        auto kNode = &dummy;
        while (true) {
            for (int i = 0; i < k && kNode; ++i) {
                kNode = kNode->next;
            }
            if (!kNode) break; // 不足k个

            // 反转kGroup
            auto p = prev->next;
            kNode = p;
            for (int i = 0; i < k; ++i) {
                auto next = p->next;
                p->next = prev->next;
                prev->next = p;
                p = next;
            }
            kNode->next = p;
            
            prev = kNode;
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
    auto head = solution.reverseKGroup(&l1, 2);
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    
    return 0;
}
