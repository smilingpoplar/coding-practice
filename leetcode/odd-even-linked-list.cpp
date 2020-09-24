//
//  odd-even-linked-list
//  https://leetcode.com/problems/odd-even-linked-list/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return NULL;
        ListNode dummyOdd(-1), dummyEven(-1);
        auto odd = &dummyOdd, even = &dummyEven;
        while (head) {
            odd->next = head;
            odd = odd->next;
            even->next = head->next;
            even = even->next;
            head = even ? even->next : NULL;
        }
        odd->next = dummyEven.next;
        return dummyOdd.next;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
