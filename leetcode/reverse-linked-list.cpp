//
//  reverse-linked-list
//  https://leetcode.com/problems/reverse-linked-list/
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
    ListNode* reverseList(ListNode* head) {
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
    l1.next = &l2;
    l2.next = &l3;
    
    Solution solution;
    auto head = solution.reverseList(&l1);
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    
    return 0;
}
