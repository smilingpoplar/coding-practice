//
//  palindrome-linked-list
//  https://leetcode.com/problems/palindrome-linked-list/
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
    bool isPalindrome(ListNode *head) {
        if (!head) return true;
        // 快慢指针，让slow指向前半段尾节点
        auto fast = head->next, slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        auto l1 = head, l2 = reverse(slow->next);
        while (l2) {
            if (l1->val != l2->val) return false;
            l1 = l1->next;
            l2 = l2->next;
        }
        return true;
    }

    ListNode* reverse(ListNode* head) {
        ListNode *list = NULL;
        while (head) {
            auto next = head->next;
            head->next = list;
            list = head;
            head = next;
        }
        return list;
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
