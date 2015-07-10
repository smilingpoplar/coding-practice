//
//  palindrome-linked-list
//  https://leetcode.com/problems/palindrome-linked-list/
//
//  Created by smilingpoplar on 15/7/10.
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
    bool isPalindrome(ListNode *head) {
        if (!head) return true;
        // 快慢指针找中间节点（偶数时偏左奇数时中间）
        auto fast = head;
        auto slow = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        // 后半段稍短，将后半段反转
        auto head2 = slow->next;
        slow->next = NULL;
        ListNode dummy(-1);
        while (head2) {
            auto next = head2->next;
            head2->next = dummy.next;
            dummy.next = head2;
            head2 = next;
        }
        head2 = dummy.next;
        // 比较
        while (head && head2) {
            if (head->val != head2->val) return false;
            head = head->next;
            head2 = head2->next;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    ListNode l1(1);
    ListNode l2(2);
    ListNode l3(3);
    ListNode l4(2);
    ListNode l5(1);
    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    l4.next = &l5;
    
    Solution solution;
    cout << solution.isPalindrome(&l1);
    
    return 0;
}
