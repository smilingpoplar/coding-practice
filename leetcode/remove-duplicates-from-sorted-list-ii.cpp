//
//  remove-duplicates-from-sorted-list-ii
//  https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
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
        ListNode dummy(-1);
        dummy.next = head;
        auto node = &dummy;
        
        while (node->next) {
            if (node->next->next && node->next->val == node->next->next->val) {
                int val = node->next->val; // 删除有这个值的节点
                while (node->next && node->next->val == val) {
                    auto next = node->next->next;
                    delete node->next;
                    node->next = next;
                }
            } else {
                node = node->next;
            }
        }
        return dummy.next;
    }
};

int main(int argc, const char * argv[]) {
    ListNode *l1 = new ListNode(1);
    ListNode *l2 = new ListNode(1);
    ListNode *l3 = new ListNode(2);
    ListNode *l4 = new ListNode(3);
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
