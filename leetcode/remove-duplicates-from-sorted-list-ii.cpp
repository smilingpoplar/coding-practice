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
        dummy.next = head; // 在head前添加dummy节点
        auto prev = &dummy;
        
        while (prev->next) { // 当前节点非空
            if (prev->next->next && prev->next->val == prev->next->next->val) {
                int val = prev->next->val;
                while (prev->next && prev->next->val == val) { // 删除这些有相等值的节点
                    auto toDelete = prev->next;
                    prev->next = prev->next->next;
                    delete toDelete;
                }
            } else {
                prev = prev->next;
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
