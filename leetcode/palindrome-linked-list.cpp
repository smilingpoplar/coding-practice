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
        // 快慢指针找中间节点
        auto fast = head, slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        slow = reverse(slow);
        fast = head;

        while (fast && slow) {
            if (fast->val != slow->val) return false;
            fast = fast->next;
            slow = slow->next;
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
